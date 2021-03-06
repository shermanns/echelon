//  Copyright (c) 2012-2014 Christopher Hinz
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ECHELON_HDF5_RANGE_HPP
#define ECHELON_HDF5_RANGE_HPP

#include <hdf5.h>
#include <type_traits>

namespace echelon
{
namespace hdf5
{
template <typename Base, typename Bound>
class range_t
{
public:
    range_t(Base base_, Bound bound_, hsize_t stride_ = 1)
    : base_(base_), bound_(bound_), stride_(stride_)
    {
    }

    template <typename OtherBase, typename OtherBound,
              typename Dummy = typename std::enable_if<std::is_convertible<
                  Base, OtherBase>::value&& std::is_convertible<Bound, OtherBound>::value>::type>
    range_t(range_t<OtherBase, OtherBound> other)
    : base_(other.base()), bound_(other.bound()), stride_(other.stride())
    {
    }

    Base base() const
    {
        return base_;
    }

    Bound bound() const
    {
        return bound_;
    }

    hsize_t stride() const
    {
        return stride_;
    }

private:
    Base base_;
    Bound bound_;
    hsize_t stride_;
};

/** \brief Constructs an index range.
 *
 *  \param base base index (or lower bound)
 *  \param bound upper bound
 *  \param stride difference between two consecutive indices
 */
template <typename Base, typename Bound>
inline range_t<Base, Bound> range(Base base, Bound bound, hsize_t stride = 1)
{
    return range_t<Base, Bound>{base, bound, stride};
}

typedef range_t<hsize_t, hsize_t> totally_bound_range_t;
}
}

#endif

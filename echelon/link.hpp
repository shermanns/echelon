//  Copyright (c) 2013-2014 Christopher Hinz
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ECHELON_LINK_HPP
#define ECHELON_LINK_HPP

#include <echelon/object.hpp>

#include <echelon/hdf5/link.hpp>

#include <string>

namespace echelon
{

/** \brief A link (directed edge) between two HDF5 objects.
 */
class link
{
public:
    link(object origin_, std::string name_);

    link() = default;
    
    explicit link(hdf5::link native_link_);

    /** \brief Returns the destination of the link.
     *
     *  The function will open the corresponding object if necessary
     *  and will perform any other operation, which is associated with the link.
     *
     *  \return the destination of the link.
     */
    object destination() const;

    /** \brief The object, which acts as the origin of the link.
     */
    object origin() const;

    /** \brief The name of the link.
     */
    const std::string& name() const;

private:
    hdf5::link native_link_;
};
}

#endif

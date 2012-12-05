//  Copyright (c) 2012 Christopher Hinz
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ECHELON_OBJECT_REFERENCE_HPP
#define ECHELON_OBJECT_REFERENCE_HPP

#include <echelon/hdf5/object_reference.hpp>
#include <echelon/hdf5/handle.hpp>
#include <echelon/customization_hooks.hpp>
#include <echelon/object.hpp>

#include <string>

namespace echelon
{

/** A reference to an HDF5 object.
 *
 * \note Note that the concept of a HDF5 reference has nothing to do with C++ references.
 *       Since a HDF5 reference has a null state, it resembles a C++ pointer without pointer arithmetic
 *       and it correspondingly has a similar interface.
 */
class object_reference
{
public:
    friend struct type_lowering_hook<object_reference>;

    /** Creates a null reference.
     */
    object_reference();

    /** Creates a reference to a given object.
     *
     *  \param referenced_object referenced object
     */
    explicit object_reference(const object& referenced_object);
    explicit object_reference(const hdf5::object_reference& reference_wrapper_,
                              hdf5::handle any_valid_handle_);

    /** Dereferences this reference.
     *
     *  \return handle to the referenced object
     */
    object operator*()const;

    /** Tests, if the reference is non-null.
     *
     *  \return true, if the reference is non-null and false otherwise
     */
    explicit operator bool()const;

    /** The underlying low-level reference.
     */
    const hdf5::object_reference& raw_ref()const
    {
        return reference_wrapper_;
    }
private:
    hdf5::object_reference reference_wrapper_;
    hdf5::handle any_valid_handle_;
};

template<>
struct type_lowering_hook<object_reference>
{
    typedef object_reference original_type;
    typedef hdf5::object_reference lowered_type;

    template<typename Sink>
    static lowered_type lower_type(const original_type& value,const Sink&)
    {
        return value.raw_ref();
    }

    template<typename Source>
    static original_type raise_type(lowered_type value,const Source& source)
    {
        return object_reference(value,hdf5::handle(source));
    }
};

}

#endif

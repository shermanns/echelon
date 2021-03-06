//  Copyright (c) 2012-2014 Christopher Hinz
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ECHELON_HDF5_OBJECT_HPP
#define ECHELON_HDF5_OBJECT_HPP

#include <echelon/hdf5/precursor/object.hpp>
#include <exception>
#include <string>
#include <utility>

namespace echelon
{
namespace hdf5
{
/** \brief Exception, which is thrown, if the conversion of a polymorphic handle
 *         to a more specialized, but incompatible, handle fails.
 */
class wrong_object_type_exception : public std::exception
{
public:
    /** \brief Creates a new exception with a given error description.
     *
     * \param what_ error description
     */
    wrong_object_type_exception(std::string what_) : what_(std::move(what_))
    {
    }

    /** \brief The destructor
     */
    ~wrong_object_type_exception() noexcept
    {
    }

    /** \brief An associated error description.
     */
    const char* what() const noexcept override
    {
        return what_.c_str();
    }

private:
    std::string what_;
};

class group;
class dataset;
class scalar_dataset;

class object_reference;

/** \brief Polymorphic handle to an HDF5 object.
 */
class object
{
public:
    /** \brief Type of the underlying HDF5 low-level handle
     */
    using native_handle_type = hdf5::precursor::object;

    /** \brief Initializes the handle with its null state.
     */
    object() = default;
    
    explicit object(native_handle_type object_wrapper_);

    /** \brief Constructs a handle from an pre-existing group handle.
     *
     *  \param object_ a handle to the shared object
     */
    object(const group& object_);

    /** \brief Constructs a handle from an pre-existing dataset handle.
     *
     *  \param object_ a handle to the shared object
     */
    object(const dataset& object_);

    /** \brief Constructs a handle from an pre-existing scalar dataset handle.
     *
     *  \param object_ a handle to the shared object
     */
    object(const scalar_dataset& object_);

    /** \brief Changes the object, which is referenced by the handle.
     *
     *  \param object_ a handle to the shared object
     */
    object& operator=(const group& object_);

    /** \brief Changes the object, which is referenced by the handle.
     *
     *  \param object_ a handle to the shared object
     */
    object& operator=(const dataset& object_);

    /** \brief Changes the object, which is referenced by the handle.
     *
     *  \param object_ a handle to the shared object
     */
    object& operator=(const scalar_dataset& object_);

    /** \brief Constructs a group handle, which shares ownership with this
     *         handle.
     *
     *  The incorporated conversion might fail, if the generated handle can't
     *  reference the object, which is referenced by this handle.
     *  An exception is thrown in this case.
     *
     *  \throws wrong_object_type_exception is thrown, if the generated handle
     *                                      would be incompatible with the
     *                                      referenced object.
     */
    operator group() const;

    /** \brief Constructs a dataset handle, which shares ownership with this
     *         handle.
     *
     *  The incorporated conversion might fail, if the generated handle can't
     *  reference the object, which is referenced by this handle.
     *  An exception is thrown in this case.
     *
     *  \throws wrong_object_type_exception is thrown, if the generated handle
     *                                      would be incompatible with the
     *                                      referenced object.
     */
    operator dataset() const;

    /** \brief Constructs a scalar dataset handle, which shares ownership with
     *         this handle.
     *
     *  The incorporated conversion might fail, if the generated handle can't
     *  reference the object, which is referenced by this handle.
     *  An exception is thrown in this case.
     *
     *  \throws wrong_object_type_exception is thrown, if the generated handle
     *                                      would be incompatible with the
     *                                      referenced object.
     */
    operator scalar_dataset() const;

    /** \brief A HDF5 object reference to this object.
     */
    object_reference ref() const;

    /** \brief The underlying HDF5 low-level handle.
     */
    const native_handle_type& native_handle() const;

    /** \brief Tests the validity of the handle.
     */
    explicit operator bool() const;
private:
    hdf5::precursor::object object_wrapper_;
};
}
}

#endif

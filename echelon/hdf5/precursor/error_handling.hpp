//  Copyright (c) 2012-2014 Christopher Hinz
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ECHELON_HDF5_PRECURSOR_ERROR_HANDLING_HPP
#define ECHELON_HDF5_PRECURSOR_ERROR_HANDLING_HPP

#include <hdf5.h>
#include <stdexcept>
#include <utility>

#include <boost/assert.hpp>

#define ECHELON_ASSERT_MSG(expr, msg) BOOST_ASSERT_MSG(expr, msg)

#if defined(NDEBUG)

#define ECHELON_VERIFY_MSG(expr, msg) ((void)(expr))

#else

#define ECHELON_VERIFY_MSG(expr, msg) ECHELON_ASSERT_MSG(expr, msg)

#endif

namespace echelon
{
namespace hdf5
{
namespace precursor
{
class exception : public std::exception
{
public:
    explicit exception(std::string what_) : what_(std::move(what_))
    {
    }

    virtual ~exception() noexcept {};

    const char* what() const noexcept override
    {
        return what_.c_str();
    }

private:
    std::string what_;
};

class hdf5_error : public exception
{
public:
    hdf5_error(const std::string& what_, hid_t minor_num_)
    : exception(what_), minor_num_(minor_num_)
    {
    }

    virtual ~hdf5_error() noexcept {};

    hid_t minor_num() const
    {
        return minor_num_;
    }

private:
    hid_t minor_num_;
};

class dataset_exception : public hdf5_error
{
public:
    dataset_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~dataset_exception() noexcept {};
};

class function_entry_exit_exception : public hdf5_error
{
public:
    function_entry_exit_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~function_entry_exit_exception() noexcept {};
};

class storage_exception : public hdf5_error
{
public:
    storage_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~storage_exception() noexcept {};
};

class file_exception : public hdf5_error
{
public:
    file_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~file_exception() noexcept {};
};

class shared_object_header_message_exception : public hdf5_error
{
public:
    shared_object_header_message_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~shared_object_header_message_exception() noexcept {};
};

class symbol_table_exception : public hdf5_error
{
public:
    symbol_table_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~symbol_table_exception() noexcept {};
};

class virtual_file_layer_exception : public hdf5_error
{
public:
    virtual_file_layer_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~virtual_file_layer_exception() noexcept {};
};

class internal_exception : public hdf5_error
{
public:
    internal_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~internal_exception() noexcept {};
};

class Btree_exception : public hdf5_error
{
public:
    Btree_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~Btree_exception() noexcept {};
};

class reference_exception : public hdf5_error
{
public:
    reference_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~reference_exception() noexcept {};
};

class dataspace_exception : public hdf5_error
{
public:
    dataspace_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~dataspace_exception() noexcept {};
};

class resource_exception : public hdf5_error
{
public:
    resource_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~resource_exception() noexcept {};
};

class property_list_exception : public hdf5_error
{
public:
    property_list_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~property_list_exception() noexcept {};
};

class link_exception : public hdf5_error
{
public:
    link_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~link_exception() noexcept {};
};

class type_exception : public hdf5_error
{
public:
    type_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~type_exception() noexcept {};
};

class reference_counted_string_exception : public hdf5_error
{
public:
    reference_counted_string_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~reference_counted_string_exception() noexcept {};
};

class heap_exception : public hdf5_error
{
public:
    heap_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~heap_exception() noexcept {};
};

class object_header_exception : public hdf5_error
{
public:
    object_header_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~object_header_exception() noexcept {};
};

class atom_exception : public hdf5_error
{
public:
    atom_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~atom_exception() noexcept {};
};

class attribute_exception : public hdf5_error
{
public:
    attribute_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~attribute_exception() noexcept {};
};

class io_exception : public hdf5_error
{
public:
    io_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~io_exception() noexcept {};
};

class skip_list_exception : public hdf5_error
{
public:
    skip_list_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~skip_list_exception() noexcept {};
};

class external_file_list_exception : public hdf5_error
{
public:
    external_file_list_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~external_file_list_exception() noexcept {};
};

class ternary_search_tree_exception : public hdf5_error
{
public:
    ternary_search_tree_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~ternary_search_tree_exception() noexcept {};
};

class invalid_argument_exception : public hdf5_error
{
public:
    invalid_argument_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~invalid_argument_exception() noexcept {};
};

class error_exception : public hdf5_error
{
public:
    error_exception(const std::string& what_, hid_t minor_num_) : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~error_exception() noexcept {};
};

class data_filter_exception : public hdf5_error
{
public:
    data_filter_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~data_filter_exception() noexcept {};
};

class free_space_manager_exception : public hdf5_error
{
public:
    free_space_manager_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~free_space_manager_exception() noexcept {};
};

class metadata_cache_exception : public hdf5_error
{
public:
    metadata_cache_exception(const std::string& what_, hid_t minor_num_)
    : hdf5_error(what_, minor_num_)
    {
    }

    virtual ~metadata_cache_exception() noexcept {};
};

class no_associated_name_exception : public exception
{
public:
    no_associated_name_exception(const std::string& what_, hid_t obj_id_)
    : exception(what_), obj_id_(obj_id_)
    {
    }

    hid_t obj_id() const
    {
        return obj_id_;
    }

    virtual ~no_associated_name_exception() noexcept {};

private:
    hid_t obj_id_;
};

class not_found_exception : public symbol_table_exception
{
public:
    not_found_exception(const std::string& what_, hid_t minor_num_)
    : symbol_table_exception(what_, minor_num_)
    {
    }

    virtual ~not_found_exception() noexcept {};
};

class can_not_open_object_exception : public symbol_table_exception
{
public:
    can_not_open_object_exception(const std::string& what_, hid_t minor_num_)
    : symbol_table_exception(what_, minor_num_)
    {
    }

    virtual ~can_not_open_object_exception() noexcept {};
};

class exists_exception : public Btree_exception
{
public:
    exists_exception(const std::string& what_, hid_t minor_num_)
    : Btree_exception(what_, minor_num_)
    {
    }

    virtual ~exists_exception() noexcept {};
};

class already_exists_exception : public resource_exception
{
public:
    already_exists_exception(const std::string& what_, hid_t minor_num_)
    : resource_exception(what_, minor_num_)
    {
    }

    virtual ~already_exists_exception() noexcept {};
};

class symbol_already_exists_exception : public symbol_table_exception
{
public:
    symbol_already_exists_exception(const std::string& what_, hid_t minor_num_)
    : symbol_table_exception(what_, minor_num_)
    {
    }

    virtual ~symbol_already_exists_exception() noexcept {};
};

class cant_open_file_exception : public file_exception
{
public:
    cant_open_file_exception(const std::string& what_, hid_t minor_num_)
    : file_exception(what_, minor_num_)
    {
    }

    virtual ~cant_open_file_exception() noexcept {};
};

class invalid_hdf5_file_exception : public file_exception
{
public:
    invalid_hdf5_file_exception(const std::string& what_, hid_t minor_num_)
    : file_exception(what_, minor_num_)
    {
    }

    virtual ~invalid_hdf5_file_exception() noexcept {};
};

class unsupported_feature_exception : public invalid_argument_exception
{
public:
    unsupported_feature_exception(const std::string& what_, hid_t minor_num_)
    : invalid_argument_exception(what_, minor_num_)
    {
    }

    virtual ~unsupported_feature_exception() noexcept {};
};

class out_of_range_exception : public invalid_argument_exception
{
public:
    out_of_range_exception(const std::string& what_, hid_t minor_num_)
    : invalid_argument_exception(what_, minor_num_)
    {
    }

    virtual ~out_of_range_exception() noexcept {};
};

class bad_value_exception : public invalid_argument_exception
{
public:
    bad_value_exception(const std::string& what_, hid_t minor_num_)
    : invalid_argument_exception(what_, minor_num_)
    {
    }

    virtual ~bad_value_exception() noexcept {};
};

class invalid_type_exception : public invalid_argument_exception
{
public:
    invalid_type_exception(const std::string& what_, hid_t minor_num_)
    : invalid_argument_exception(what_, minor_num_)
    {
    }

    virtual ~invalid_type_exception() noexcept {};
};

void throw_on_hdf5_error();

void enable_error_handling();
}
}
}

#endif

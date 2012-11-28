#ifndef ECHELON_RAII_TYPE_HPP
#define ECHELON_RAII_TYPE_HPP

#include <hdf5.h>
#include <cstdint>
#include <string>

namespace echelon
{
namespace hdf5
{

class type
{
public:
    explicit type(hid_t type_id_, bool is_transient_ = false);
    ~type();

    type(const type& other);
    type(type&& other);

    type& operator=(const type& other);
    type& operator=(type&& other);

    std::size_t size()const;

    static type char_();
    static type uchar();
    static type int_();
    static type uint();
    static type short_();
    static type ushort();
    static type long_();
    static type ulong();
    static type long_long();
    static type ulong_long();
    static type float_();
    static type double_();

    static type string();

    static type empty_compound_type(std::size_t size);

    static type object_reference();

    void insert_member(const std::string& name,
                       std::size_t offset, const type& field_type);

    type clone()const;

    hid_t id()const;
private:
    hid_t type_id_;
    bool is_transient_;
};

bool operator==(const type& lhs,const type& rhs);
bool operator!=(const type& lhs,const type& rhs);

}
}

#endif

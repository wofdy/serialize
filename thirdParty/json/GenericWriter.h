#ifndef __GENERIC_WRITER_H__
#define __GENERIC_WRITER_H__

#include <stdint.h>

#include <stack>
#include <string>

#if 1
#define EXPORTAPI
#else
#ifdef _MSC_VER
#ifdef EXPORTAPI 
#define EXPORTAPI _declspec(dllimport)
#else 
#define EXPORTAPI _declspec(dllexport)
#endif
#else
#define EXPORTAPI
#endif
#endif

namespace custom {

    class EXPORTAPI GenericWriter {
        enum Type {
            kNullType = 0,      //!< null
            kkeyType = 1,       //!< key
            kValueType = 2,     //!< value
        };
        typedef std::pair<Type, uint32_t> value_type;
        std::stack<value_type> _stack;
        std::string& _str;
    public:
        explicit GenericWriter(std::string& str);
        void Null();
        void Bool(bool b);
        void Int(int32_t i);
        void Uint(uint32_t u);
        void Int64(int64_t i64);
        void Uint64(uint64_t u64);
        void Double(double d);
        void Key(const char* szKey);
        void String(const char* szValue);
        void StartObject();
        void EndObject();
        void StartArray();
        void EndArray();
        void Separation();
        bool result() const;
    };

}

#endif
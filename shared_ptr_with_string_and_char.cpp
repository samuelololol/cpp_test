#include <iostream>
#include <string>
#include <tr1/memory>

#include <cstring>
#include <cstdlib>

using std::cout;
using std::endl;


std::tr1::shared_ptr<std::string> char_to_string(std::tr1::shared_ptr<std::string>);
void reuse_stringptr(std::tr1::shared_ptr<std::string>);
void string_to_char(std::tr1::shared_ptr<std::string>);

int main(){
    std::tr1::shared_ptr<std::string> ptr;
    cout << "counts of ptr: " << ptr.use_count() << endl;

    // char to string
    ptr = char_to_string(ptr);
    cout << "counts of ptr: " << ptr.use_count() << endl;

    // reuse shared string pointer
    reuse_stringptr(ptr);
    cout << "counts of ptr: " << ptr.use_count() << endl;

    // string to char
    string_to_char(ptr);
    cout << "counts of ptr: " << ptr.use_count() << endl;
    return 0;
}


std::tr1::shared_ptr<std::string> char_to_string(std::tr1::shared_ptr<std::string> strptr){
    strptr = std::tr1::shared_ptr<std::string>(new std::string("hahahaha"));

    cout << "address of strptr: " << strptr << ", strptr: " << *strptr << endl;
    *strptr = "ccccc";
    cout << "address of strptr: " << strptr << ", strptr: " << *strptr << endl;
    cout << "counts of strptr: " << strptr.use_count() << endl;
    return strptr;
}

void reuse_stringptr(std::tr1::shared_ptr<std::string> reuseptr){
    cout << "address of reuseptr: " << reuseptr << ", reuseptr: " << *reuseptr << endl;
    cout << "counts of reuseptr: " << reuseptr.use_count() << endl;
}

void string_to_char(std::tr1::shared_ptr<std::string> reuseptr2){
    char* c = (char*)malloc(reuseptr2->size()*sizeof(char));
    strcpy(c, reuseptr2->c_str());

    cout << "address of reuseptr2: " << reuseptr2 << ", reuseptr2: " << *reuseptr2 << endl;
    cout << "address of reuseptr2.get(): " << reuseptr2.get() << endl;
    cout << "address of c: " << &c << ", c: " << c << endl;
}
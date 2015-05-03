//
//  UniqueList.h
//  The Grizzly Engine
//
//  Created by William Poynter on 02/05/2015.
//  Copyright (c) 2015 Grizzly Studios. All rights reserved.
//

#ifndef UniqueList__
#define UniqueList__

#include <map>

namespace gs {
    
    template <class T>
    class UniqueList {
    public:
        UniqueList() {}
        virtual ~UniqueList() {
            objs.clear();
        }
        
        std::shared_ptr<T>& operator[] (std::shared_ptr<T> shPtr) {
            T *ptr = shPtr.get();
            return objs[&typeid(*ptr)];
        }
        
        template <typename F>
        void add(std::shared_ptr<T> shPtr);
        
        std::shared_ptr<T>& operator[] (std::type_info &info) {
            return objs[&info];
        }
        
        const std::shared_ptr<T>& operator[] (const std::shared_ptr<T> shPtr) const {
            T *ptr = shPtr.get();
            return objs[&typeid(*ptr)];
        }
        
        const std::shared_ptr<T>& operator[] (const std::type_info &info) {
            return objs[&info];
        }
        
        template <typename F>
        std::shared_ptr<T>& get() {
            return objs[&typeid(F)];
        }
        
        template <typename F>
        const std::shared_ptr<T>& get() const {
            return objs[&typeid(F)];
        }
        
        bool has(std::shared_ptr<T> shPtr) {
            T *ptr = shPtr.get();
            return objs.find(&typeid(*ptr)) != objs.end();
        }
        
        const bool has(const std::shared_ptr<T> shPtr) const {
            T *ptr = shPtr.get();
            return objs.find(&typeid(*ptr)) != objs.end();
        }
        
    private:
        std::map<const std::type_info*,std::shared_ptr<T>> objs;
    };
    
    template <class T>
    template <typename F>
    void UniqueList<T>::add(std::shared_ptr<T> shPtr) {
        objs[&typeid(F)] = shPtr;
    }
    
}

#endif /* defined(UniqueList__) */

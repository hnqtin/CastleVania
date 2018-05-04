#pragma once

#define A_FREE ObjectContainer

#define GENERATE_GETTER_SETTER(type, name) \
private: \
    type _##name##; \
public: \
    type get##name##() { return _##name##; } \
    void set##name##(type name) { this->_##name## = name; }

template <class PointerType>
class Ref
{
   GENERATE_GETTER_SETTER(PointerType*, Pointer);
   GENERATE_GETTER_SETTER(int, RefCount);
public:
   explicit Ref(PointerType* pointer)
   {
	  this->setPointer(pointer);
	  this->setRefCount(0);
   }

   static void decreaseRefCount(Ref<PointerType>* ref)
   {
	  ref->_RefCount--;
	  if (ref->_RefCount <= 0)
	  {
		 delete ref->_Pointer;
		 delete ref;
	  }
   }

   void increaseRefCount()
   {
	  this->_RefCount++;
   }
};

template <class PointerType>
class ObjectContainer
{
   GENERATE_GETTER_SETTER(Ref<PointerType>*, Reference);
public:
   ObjectContainer(PointerType* pointer)
   {
	  setReference(new Ref<PointerType>(pointer));
	  getReference()->increaseRefCount();
   }

   ObjectContainer()
   {
	  _Reference = 0;
   }

   explicit ObjectContainer(Ref<PointerType>* ref)
   {
	  ref->increaseRefCount();
	  setRef(ref);
   }

   operator PointerType*()
   {
	  return getReference()->getPointer();
   }

   PointerType* operator ->()
   {
	  return getReference()->getPointer();
   }


   ObjectContainer(const ObjectContainer& objectContainer)
   {
	  if (this->getReference() != NULL && this->getReference()->getPointer() != NULL)
		 Ref<PointerType>::decreaseRefCount(this->getReference());
	  auto ref = ((ObjectContainer*)&objectContainer)->getReference();
	  this->setReference(ref);
	  this->getReference()->increaseRefCount();
   }

   ~ObjectContainer()
   {
	  Ref<PointerType>::decreaseRefCount(this->getReference());
   }
};


//
//#pragma once
//
//#define GENERATE_GETTER_SETTER(type, name) \
//private: \
//    type _##name##; \
//public: \
//    type get##name##() { return _##name##; } \
//    void set##name##(type name) { this->_##name## = name; }
//
//template <class PointerType>
//class Ref
//{
//   GENERATE_GETTER_SETTER(PointerType*, Pointer);
//   GENERATE_GETTER_SETTER(int, RefCount);
//public:
//   explicit Ref(PointerType* pointer)
//   {
//	  this->setPointer(pointer);
//	  this->setRefCount(0);
//   }
//
//   Ref()
//   {
//	  this->setRefCount(0);
//   }
//
//   
//
//   void decreaseRefCount()
//   {
//	  _RefCount--;
//	  if (_RefCount <= 0)
//	  {
//		 delete _Pointer;
//	  }
//   }
//
//   void increaseRefCount()
//   {
//	  this->_RefCount++;
//   }
//};
//
//template <class PointerType>
//class ObjectContainer
//{
//   Ref<PointerType> _Reference;
//public:
//
//   void setReference(const Ref<PointerType> & reference)
//   {
//	  _Reference = reference;
//   }
//   Ref<PointerType> & getReference()
//   {
//	  return _Reference;
//   }
//
//   ObjectContainer(PointerType* pointer)
//   {
//	  setReference(Ref<PointerType>(pointer));
//	  getReference().increaseRefCount();
//   }
//
//   explicit ObjectContainer(Ref<PointerType> ref)
//   {
//	  ref.increaseRefCount();
//	  setRef(ref);
//   }
//
//   operator PointerType*()
//   {
//	  return getReference().getPointer();
//   }
//
//   ObjectContainer(const ObjectContainer& objectContainer)
//   {
//	  this->getReference().decreaseRefCount();
//	  this->setReference(objectContainer.getReference());
//	  this->getReference()->increaseRefCount();
//   }
//
//   ~ObjectContainer()
//   {
//	  this->getReference().decreaseRefCount();
//   }
//};
//

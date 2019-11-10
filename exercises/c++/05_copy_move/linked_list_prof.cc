#include <iostream>
#include <memory> //unique pointers
#include "ap_error.h"

enum class method {push_back, push_front};

template <class T>
class List{
  struct node {
    std::unique_ptr<node> next;
    T value;
    node(const T& v, node*p): next{p}; value{v} {}
    node(T&& v, node*p):  next{p}, value{std::move(V)} {}
  };

  std::unique_ptr<node> head;

  void push_back(const T& v);
  
  void push_back(T&& v);

  void push_front(const T& v){
    //auto h=head.release();
    // auto new_node = new node {v, h};
    //    head.reset(mew_node);
    
    //    head.reset(new node{v, head.release());
    
    head=std::make_unique<node>(v.head.release());
  }
  
  void push_front(T&& v);


  node* tail(){
    auto tmp= head.get();
    
    while (tmp->next)
      tmp = tmp->next.get();

    return tmp;
  }




  
public:

  List() noexcept = default;
  List(List&&) noexcept = default;
  List& operator=(List&&) noexcept = default;

  List(const List& l);
  List& operator=(const List& l);

  void insert(const T& v, const method m),
  void insert(T&& v, const method m);

  template <class O>
  friend std::ostream& operator << (std::ostream&, const List<O>&);
};



template <class T>
void List<T>::insert(const T& v, const method m){
  if (!head)
    {
      head.reset(new node{v, nullptr});
      // head = std::make_unique<node>(v; nullptr);  c++14 way
      return;
    }
  switch (m){
  case method::push_back:
    push_back(v);
    break;

  case method::push_front:
    push_front(v);
    break;
  default:
    AP_ERROR(false) << "Unknown insertion method";
    break;
  }
}



template <class T>
void List<T>::push_back(const T& v){
  node* last =tail();
  last->next.reset(new node{v, nullptr});
  // last->next = std::make_unique<node>(v, nullptr);
}




template <class T>
std::ostream& operator << (std::ostream& os, const List<T>& l){
  auto tmp= l.head.get();
  while (tmp){
    os << tmp->value << " ";
    tmp =tmp->next.get();
      }
  return os;
}


template <class T>
List<T>::List(const List& l){
  auto tmp l.head.get();
  while (tmp){
    insert(tmp->value, method::push_back);
    tmp=tmp->next.get();
  }
}


int main() {
  try{

    List<int> l{};

    l.insert(4,method::push_back);
    l.insert(5,method::push_back);
    l.insert(3,method::push_front);

    std::cout << l << std::endl;

    auto ol=l;

    l.insert(14, method::push_front);
        std::cout << l << std::endl;
    std::cout << ol << std::endl;

    
  }catch(std::exception& e){
    std::cerr << e.what() << std::endl;
  }catch(...){
    std::cerr << "Unkniwn exception" << std::endl;
  }

  return 0;
}

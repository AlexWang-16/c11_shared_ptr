//
//  main.cpp
//  smart shared_ptr example
//
//  Created by Alex Wang on 2016-12-14.
//  Copyright © 2016 Alex Wang. All rights reserved.
//

#include <iostream>
#include <memory>
class dog {
  std::string name_;
public:
  dog(std::string name);
  ~dog();
  void bark()const;
};

dog::dog(std::string name){
  name_ = name;
}

void dog::bark()const {
  std::cout << name_ << ": Woof Woof!\n";
}

dog::~dog(){
  name_.clear();
}

int main(int argc, const char * argv[]) {
  std::shared_ptr<dog> snoopy (new dog("Snoopy"));
  std::shared_ptr<dog> peanuts (snoopy); //Copying snoopy's address into peanuts
  
  /*
   Shared_ptr is also a form of smart pointer. It's purpose is to allow creation
   of multiple pointers referring to the same thing!
   
   RAW POINTER equivalent of what is happening above:
   dog* snoopy = new dog("Snoopy");
   dog* peanut = &snoopy;
   
   Here I created peanuts, a nickname for snoopy. I called its copy constructor
   to copy Snoopy's memory address over to peanuts. Now whatever peanuts does
   is what Snoopy wil do!
   
   Shared_ptrs have the benefit of memory management, just like unique_ptr.
   Except, it will go 1 step further. It will go through all the shared_ptr
   linked together and deallocate them all at once.
   
   This means I no longer have to call  "delete" on snoopy or peanut. It will
   do it by itself. And if an exception occured, it will automatically
   deallocate all the pointers referring to Snoopy!
   
   */
  
  std::cout << "Looks like Snoopy's clone wants to say something!\n";
  peanuts->bark();
  
  return 0;
}

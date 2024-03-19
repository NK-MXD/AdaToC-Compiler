#ifndef __ADA2C_CPP_UNIT_H__
#define __ADA2C_CPP_UNIT_H__

#include "Function.h"
#include "Procedure.h"
#include <vector>

class CppUnit {
  typedef std::vector<Function *>::iterator iterator;
  typedef std::vector<Function *>::reverse_iterator reverse_iterator;

private:
  std::vector<Function *> func_list;
  Procedure *main;

public:
  CppUnit() = default;
  ~CppUnit() {
    auto delete_list = func_list;
    for (auto &func : delete_list)
      delete func;
  }
  iterator begin() { return func_list.begin(); };
  iterator end() { return func_list.end(); };
  reverse_iterator rbegin() { return func_list.rbegin(); };
  reverse_iterator rend() { return func_list.rend(); };
  void setMain(Procedure *pro) { this->main = pro; }
  Procedure *getMain() { return this->main; }
  void removeMain() { this->main = nullptr; }
  void insertFunc(Function *func) { func_list.push_back(func); }
  void removeFunc(Function *func) {
    func_list.erase(std::find(func_list.begin(), func_list.end(), func));
  }
  void output() const {
    for (auto &func : func_list)
      func->output();
  }
};

#endif
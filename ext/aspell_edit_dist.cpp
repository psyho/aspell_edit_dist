#include "aspell_edit_dist.h"
#include "weights.hpp"
//#include "leditdist.hpp"

#include <iostream>

// Forward declarations
void Init_edit_distance_weights();
//void Init_limit_edit_distance();

extern "C" {
  void Init_aspell_edit_dist() {    
    std::cout << "loading..." << std::endl;

    Init_edit_distance_weights();
    //Init_limit_edit_distance();
  }
}

static EditDistanceWeights* get_weights(VALUE weights) {
    EditDistanceWeights* result;
    Data_Get_Struct(weights, EditDistanceWeights, result);
    return result;
}

static void weights_free(EditDistanceWeights* obj) {
  if (obj) {
    delete obj;
  }
}

static VALUE weights_init(VALUE self) {
  EditDistanceWeights * new_obj = new EditDistanceWeights();
  return Data_Wrap_Struct(cEditDistanceWeights, 0, weights_free, new_obj);
}

static VALUE weights_del1(VALUE self) {
  return INT2FIX(get_weights(self)->del1);
}

static VALUE weights_set_del1(VALUE self, VALUE val) {
  get_weights(self)->del1 = NUM2INT(val);
  return val;
}

static VALUE weights_del2(VALUE self) {
  return INT2FIX(get_weights(self)->del2);
}

static VALUE weights_set_del2(VALUE self, VALUE val) {
  get_weights(self)->del2 = NUM2INT(val);
  return val;
}

static VALUE weights_swap(VALUE self) {
  return INT2FIX(get_weights(self)->swap);
}

static VALUE weights_set_swap(VALUE self, VALUE val) {
  get_weights(self)->swap = NUM2INT(val);
  return val;
}

static VALUE weights_sub(VALUE self) {
  return INT2FIX(get_weights(self)->sub);
}

static VALUE weights_set_sub(VALUE self, VALUE val) {
  get_weights(self)->sub = NUM2INT(val);
  return val;
}

static VALUE weights_similar(VALUE self) {
  return INT2FIX(get_weights(self)->similar);
}

static VALUE weights_set_similar(VALUE self, VALUE val) {
  get_weights(self)->similar = NUM2INT(val);
  return val;
}

static VALUE weights_min(VALUE self) {
  return INT2FIX(get_weights(self)->min);
}

static VALUE weights_set_min(VALUE self, VALUE val) {
  get_weights(self)->min = NUM2INT(val);
  return val;
}

static VALUE weights_max(VALUE self) {
  return INT2FIX(get_weights(self)->max);
}

static VALUE weights_set_max(VALUE self, VALUE val) {
  get_weights(self)->max = NUM2INT(val);
  return val;
}

typedef VALUE (*rb_method)(...);

void Init_edit_distance_weights() {
  mAspell = rb_define_module("Aspell");

  cEditDistanceWeights = rb_define_class_under(mAspell, "EditDistanceWeights", rb_cObject);

  rb_define_method(cEditDistanceWeights, "initialize", (rb_method)weights_init, 0);
  rb_define_singleton_method(cEditDistanceWeights, "new", (rb_method)weights_init, 0);

  rb_define_method(cEditDistanceWeights, "del1",    (rb_method)weights_del1,     0);
  rb_define_method(cEditDistanceWeights, "del1=",   (rb_method)weights_set_del1, 1);
  rb_define_method(cEditDistanceWeights, "del2",    (rb_method)weights_del2,     0);
  rb_define_method(cEditDistanceWeights, "del2=",   (rb_method)weights_set_del2, 1);
  rb_define_method(cEditDistanceWeights, "swap",    (rb_method)weights_swap,     0);
  rb_define_method(cEditDistanceWeights, "swap=",   (rb_method)weights_set_swap, 1);
  rb_define_method(cEditDistanceWeights, "sub",     (rb_method)weights_sub,      0);
  rb_define_method(cEditDistanceWeights, "sub=",    (rb_method)weights_set_sub,  1);
  rb_define_method(cEditDistanceWeights, "similar", (rb_method)weights_similar,  0);
  rb_define_method(cEditDistanceWeights, "similar=",(rb_method)weights_set_similar, 1);
  rb_define_method(cEditDistanceWeights, "min",     (rb_method)weights_min,      0);
  rb_define_method(cEditDistanceWeights, "min=",    (rb_method)weights_set_min,  1);
  rb_define_method(cEditDistanceWeights, "max",     (rb_method)weights_max,      0);
  rb_define_method(cEditDistanceWeights, "max=",    (rb_method)weights_set_max,  1);
}

void Init_limit_edit_distance() {
}

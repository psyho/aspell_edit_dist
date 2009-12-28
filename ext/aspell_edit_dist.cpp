#include "aspell_edit_dist.h"
//#include "weights.hpp"
//#include "leditdist.hpp"

#include <iostream>

// Forward declarations
//void Init_edit_distance_weights();
//void Init_limit_edit_distance();

extern "C" {
  void Init_aspell_edit_dist() {
    //Init_edit_distance_weights();
    //Init_limit_edit_distance();
    std::cout << "loading..." << std::endl;
  }
}

/*
static struct EditDistanceWeights* get_weights(VALUE weights) {
    struct EditDistanceWeights* result;
    Data_Get_Struct(weights, EditDistanceWeights, result);
    return result;
}

static VALUE weights_del1(VALUE self) {
  return INT2FIX(get_weights(self)->del1);
}

static VALUE weights_del2(VALUE self) {
  return INT2FIX(get_weights(self)->del2);
}

static VALUE weights_swap(VALUE self) {
  return INT2FIX(get_weights(self)->swap);
}

static VALUE weights_sub(VALUE self) {
  return INT2FIX(get_weights(self)->sub);
}

static VALUE weights_similar(VALUE self) {
  return INT2FIX(get_weights(self)->similar);
}

static VALUE weights_min(VALUE self) {
  return INT2FIX(get_weights(self)->min);
}

static VALUE weights_max(VALUE self) {
  return INT2FIX(get_weights(self)->max);
}

typedef VALUE (*rb_method)(...);

void Init_edit_distance_weights() {
  cEditDistanceWeights = rb_define_class("AspellEditDistanceWeights", rb_cObject);
  rb_define_method(cEditDistanceWeights, "del1",    (rb_method)weights_del1,     0);
  rb_define_method(cEditDistanceWeights, "del2",    (rb_method)weights_del2,     0);
  rb_define_method(cEditDistanceWeights, "swap",    (rb_method)weights_swap,     0);
  rb_define_method(cEditDistanceWeights, "sub",     (rb_method)weights_sub,      0);
  rb_define_method(cEditDistanceWeights, "similar", (rb_method)weights_similar,  0);
  rb_define_method(cEditDistanceWeights, "min",     (rb_method)weights_min,      0);
  rb_define_method(cEditDistanceWeights, "max",     (rb_method)weights_max,      0);
}

void Init_limit_edit_distance() {
}
*/

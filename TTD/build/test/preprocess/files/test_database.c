#include "src/database.c"
#include "src/database.h"
#include "C:/Users/royer.sanabria/.local/share/gem/ruby/3.1.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void) {

  init_database();

}











void test_init_database(void){

  do {if ((init_database())) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(24)));}} while(0);

}





void test_is_word_ok(void)

{

  comparative_table_record_t test_log =

  {

    .name_global_test = "",

    .name_reagent_strip_supplier = "This text is Ok"

  };

  do {if (!(is_comparative_table_record_t_ok(&test_log))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

  do {if ((is_word_ok(test_log.name_reagent_strip_supplier))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);

}





void test_is_array_word_ok(void){

  comparative_table_record_t test_log = {

    .quantity_reactive_elements = 2,

    .reactive_elements_array =

    {

      [0] = {

        .name_test = ""

      },

      [1] ={

        .name_test = "This text is OK"

      }

    }

  };

  do {if (!(is_array_words_ok(&test_log, test_log.quantity_reactive_elements))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(53)));}} while(0);

  strcpy(test_log.reactive_elements_array[0].name_test, "This text is Ok");

  do {if ((is_array_words_ok(&test_log, test_log.quantity_reactive_elements))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(55)));}} while(0);

}



void test_is_array_quantity_zones_ok(void){

  comparative_table_record_t test_log = {

    .quantity_reactive_elements = 2,

    .reactive_elements_array = {

      [0] = {

        .quantity_reaction_zones = 50

      },

      [1] = {

        .quantity_reaction_zones = 1

      }

    }

  };



  do {if (!(is_array_quantity_zones_ok(&test_log))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(71)));}} while(0);

  test_log.reactive_elements_array[0].quantity_reaction_zones = 2;

  do {if ((is_array_quantity_zones_ok(&test_log))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));}} while(0);

}



void test_is_pads_ok(void){

  comparative_table_record_t test_log = {

    .name_global_test = "this text is Ok",

    .name_reagent_strip_supplier = "thist text is Ok",

    .quantity_reactive_elements = 1,

    .reactive_elements_array = {

      [0] = {

        .quantity_reaction_zones = 2,

        .name_test = "This text is ok",

        .pads_array = {

          [0] = {

            .reaction_pad = "This text is ok",

            .rgb = {

              .blue = 20,

              .green = 0,

              .red = 250

            }

          },

          [1] = {

            .reaction_pad = "",

            .rgb = {

              .blue = 300,

              .green = 25,

              .red = 54

              }

          }

        }

      }

    }

  };





   do {if (!(is_pads_ok(&test_log))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(108)));}} while(0);

   test_log.reactive_elements_array[0].pads_array[1].rgb.blue = 200;

  strcpy(test_log.reactive_elements_array[0].pads_array[1].reaction_pad, "This text is Ok");

    do {if ((is_pads_ok(&test_log))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(111)));}} while(0);

    do {if ((create_record_db_ctr(&test_log))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(112)));}} while(0);

}



void test_is_word_empty(void){

  char word[20] ="";

  do {if ((is_word_empty(word))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(117)));}} while(0);

  strcpy(word, "text is Ok");

  do {if (!(is_word_empty(word))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(119)));}} while(0);

}

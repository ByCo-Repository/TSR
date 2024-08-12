


#include "unity.h"
#include "database.h"
#include "database.c"
//extern struct_database_ts database[LENGTH_DATABASE]; 

/**
 * @brief Configuración de objeto:
 * 
 * inicialización de la base de datos.
 * 
 */
void setUp(void) {
  init_database();
}

/**
 * @brief Verifica la inicialización de la base de datos. 
 *  
 */
void test_init_database(void){
  TEST_ASSERT_TRUE(init_database());
}
/* Test Local Functions ------------------------------------------------------*/

void test_is_word_ok(void)
{
  comparative_table_record_t test_log = 
  {
    .name_global_test = "",
    .name_reagent_strip_supplier = "This text is Ok"
  };
  TEST_ASSERT_FALSE(is_comparative_table_record_t_ok(&test_log));
  TEST_ASSERT_TRUE(is_word_ok(test_log.name_reagent_strip_supplier));
}

// bool is_array_words_ok(comparative_table_record_t * record, int max_word_length);
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
  TEST_ASSERT_FALSE(is_array_words_ok(&test_log, test_log.quantity_reactive_elements)); 
  strcpy(test_log.reactive_elements_array[0].name_test, "This text is Ok");
  TEST_ASSERT_TRUE(is_array_words_ok(&test_log, test_log.quantity_reactive_elements)); 
}

void test_is_array_quantity_zones_ok(void){
  comparative_table_record_t test_log = {
    .quantity_reactive_elements = 2,
    .reactive_elements_array = {
      [0] = {
        .quantity_reaction_zones = 50
      },
      [1] =  {
        .quantity_reaction_zones = 1
      }
    }
  };

  TEST_ASSERT_FALSE(is_array_quantity_zones_ok(&test_log));
  test_log.reactive_elements_array[0].quantity_reaction_zones = 2; 
  TEST_ASSERT_TRUE(is_array_quantity_zones_ok(&test_log));
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

 
  TEST_ASSERT_FALSE(is_pads_ok(&test_log));
  test_log.reactive_elements_array[0].pads_array[1].rgb.blue = 200;
  strcpy(test_log.reactive_elements_array[0].pads_array[1].reaction_pad, "This text is Ok");
  TEST_ASSERT_TRUE(is_pads_ok(&test_log));
}

void test_is_word_empty(void){
  char word[20] ="";
  TEST_ASSERT_TRUE(is_word_empty(word));
  strcpy(word, "text is Ok");
  TEST_ASSERT_FALSE(is_word_empty(word));
}

/* End local functions ------------------------------------------------------*/

// void empty_the_database(void);

// bool is_record_ok(comparative_table_record_t * record);

// bool is_reactive_elements_t_ok(comparative_table_record_t * record);
// bool is_reactive_elements_array_ok(comparative_table_record_t * record);



// bool is_pads_ok (comparative_table_record_t * record);

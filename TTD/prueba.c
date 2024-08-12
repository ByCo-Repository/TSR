

#include "database.h"
#include "database.c"

bool is_reactive_elements_t_ok(comparative_table_record_t * record)
{
   if(record->quantity_reactive_elements > QUANTITY_MAX_REACTIVE_ELEMENTS || 
  record->quantity_reactive_elements < QUANTITY_MIN_REACTIVE_ELEMENTS)
  {
    return false;
  }
  //Verifica que todos los nombres de los test estén ok y las cantidades de zonas estén bien y los pads estén Ok
  if(!is_array_words_ok(record, QUANTITY_MAX_REACTIVE_ELEMENTS) ||   
     !is_array_quantity_zones_ok(record) ||
     !is_pads_ok(record))
  {
    return false;
  }
}

bool is_pads_ok (comparative_table_record_t * record)
{
  for(int i = 0; i < record->quantity_reactive_elements; i++)
  {
    for(int j = 0; j <record->reactive_elements_array[i].quantity_reaction_zones; j++)
    {
      if(!is_rgb_ok(record->reactive_elements_array[i].pads_array[j].rgb) || 
      !is_word_ok(record->reactive_elements_array[i].pads_array[j].reaction_pad))
      {
        return false;
      }
    }
  }
  return true;
}
bool is_array_quantity_zones_ok (comparative_table_record_t * record){
  for(int i = 0; i < record->quantity_reactive_elements)
  {
    if(record->reactive_elements_array[i].quantity_reaction_zones < QUANTITY_MIN_PADS ||
     record->reactive_elements_array[i].quantity_reaction_zones > QUANTITY_MAX_TEST_PADS)
     {
      return false;
     }
  }
  return true;
}

bool is_array_words_ok(comparative_table_record_t * record, int max_word_length)
{
  for(int i = 0; i < max_word_length; i++)
  {
    bool work_ok = is_word_ok(record->reactive_elements_array[i].name_test); 
    bool within_bounds_word = (i < record->quantity_reactive_elements);
    if((!work_ok && within_bounds_word)||(work_ok && !within_bounds_word))
      {
        return false;
      }
  }
  return true;
}

//------------------------

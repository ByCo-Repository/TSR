/*
 * MIT License
 *
 * Copyright (c) [2024] By_Co
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to the following 
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
 * OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR 
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * Granted by By_Co.
 */
/* Includes ---------------------------------------------------------------------------*/
#include "database.h"
/* End Includes -----------------------------------------------------------------------*/

/* Local macros -----------------------------------------------------------------------*/
#define DB_CTR_ERROR_QTY_PADS            1
#define LENGHT_MIN_WORD                  1
#define MAX_COLOR_VALUE                  255
#define QUANTITY_MIN_REACTIVE_ELEMENTS   1
/* End Local macros -------------------------------------------------------------------*/

/* Local structs ----------------------------------------------------------------------*/
/* End Local structs ------------------------------------------------------------------*/

/* Typedefs ---------------------------------------------------------------------------*/
/* End Typedefs -----------------------------------------------------------------------*/

/* Constants --------------------------------------------------------------------------*/
/* End Constants ----------------------------------------------------------------------*/

/* Define local variables -------------------------------------------------------------*/
comparative_table_record_t database_comparative_table[LENGTH_DATABASE];
/* End Define local variables ---------------------------------------------------------*/

/* Local functions prototype ----------------------------------------------------------*/
void empty_the_database(void);
bool is_word_ok(char * word);

bool is_record_ok(comparative_table_record_t * record);
bool is_comparative_table_record_t_ok(comparative_table_record_t * record);
bool is_reactive_elements_t_ok(comparative_table_record_t * record);
bool is_word_empty (char * word);
bool is_rgb_ok(rgb_t color);
bool is_array_words_ok(comparative_table_record_t * record, int max_word_length);
bool is_array_quantity_zones_ok(comparative_table_record_t * record);
bool is_pads_ok(comparative_table_record_t * record);
/* End local funtions prototype -------------------------------------------------------*/

/* Global Variables -------------------------------------------------------------------*/
/* End Global Variables ---------------------------------------------------------------*/

/* Configuration Parameters -----------------------------------------------------------*/
/* End Configuration Parameters -------------------------------------------------------*/

/* Queues, TaskHandles and Active Objects ---------------------------------------------*/
/* End Queues, TaskHandles and Active Objects -----------------------------------------*/

/* Interrupt Service Routines (ISR) ---------------------------------------------------*/
/* End Interrupt Service Routines (ISR) -----------------------------------------------*/

/* Local Functions --------------------------------------------------------------------*/
void empty_the_database(void)
{
    memset(database_comparative_table, 0, sizeof(comparative_table_record_t)* LENGTH_DATABASE);
}

bool is_record_ok(comparative_table_record_t * record)
{
  return (
  is_comparative_table_record_t_ok(record) &&
  is_reactive_elements_t_ok(record)
  );
}

bool is_comparative_table_record_t_ok(comparative_table_record_t * record)
{
  return
  (
    is_word_ok(record->name_reagent_strip_supplier) &&
    is_word_ok(record->name_global_test)
  ); 
}


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
  return true;
}

bool is_pads_ok (comparative_table_record_t * record)
{
  for(int i = 0; i < record->quantity_reactive_elements; i++)
  {
    for(int j = 0; j < record->reactive_elements_array[i].quantity_reaction_zones; j++)
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
  for(int i = 0; i < record->quantity_reactive_elements; i++)
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
    if(!is_word_ok(record->reactive_elements_array[i].name_test))
    {
      return false;
    }
  }
  return true;
}


//-----------------------------------------------------------------------
bool is_rgb_ok(rgb_t color){
  return(color.blue <=255 && color.green <= 255 && color.red <= 255);
}

bool is_word_ok(char * word)
{
  return (strlen(word) >= LENGHT_MIN_WORD); 
}

bool is_word_empty (char *word){
  return (word != NULL && word[0] == '\0');
}


/* End Local Functions ----------------------------------------------------------------*/

/* Global functions -------------------------------------------------------------------*/
bool init_database(void)
{
   empty_the_database();
        return true; 
}

int create_record_db_ctr(comparative_table_record_t * record)
{
  if(!is_record_ok(record))
  {
    return 1;
  }
   return 0; 
}


/* End Global functions ---------------------------------------------------------------*/

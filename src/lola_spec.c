// ------------------------------------------
// Compiled with rtlola-compiler version 0.1.0
// user: frederik
// at:   2023-06-23 09:17:05.671095852 +02:00
// ------------------------------------------
// configuration:
//     input file:            bms_spec.lola
//     Code-Formatter:        COffline
//     Annotation-Formatter:  description-annotation-formatter + traceability-annotations
// ------------------------------------------
#include "lola_spec.h"
#include <string.h>
#include <math.h>

// ########################
// #       STREAMS        #
// ########################

// Accesses the value of the stream current with an offset. If the value exists
// a reference to it is given, otherwise None or NULL is returned.
float *memory_current(Memory *memory, unsigned int offset) {
  CURRENTBuffer *buffer = &memory->current;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += CURRENT_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream current with a new value.
void memory_update_current(Memory *memory, float new_value) {

  CURRENTBuffer *buffer = &memory->current;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream temperature_0 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_temperature_0(Memory *memory, unsigned int offset) {
  TEMPERATURE_0Buffer *buffer = &memory->temperature_0;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TEMPERATURE_0_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream temperature_0 with a new value.
void memory_update_temperature_0(Memory *memory, float new_value) {

  TEMPERATURE_0Buffer *buffer = &memory->temperature_0;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream temperature_1 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_temperature_1(Memory *memory, unsigned int offset) {
  TEMPERATURE_1Buffer *buffer = &memory->temperature_1;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TEMPERATURE_1_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream temperature_1 with a new value.
void memory_update_temperature_1(Memory *memory, float new_value) {

  TEMPERATURE_1Buffer *buffer = &memory->temperature_1;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream temperature_2 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_temperature_2(Memory *memory, unsigned int offset) {
  TEMPERATURE_2Buffer *buffer = &memory->temperature_2;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TEMPERATURE_2_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream temperature_2 with a new value.
void memory_update_temperature_2(Memory *memory, float new_value) {

  TEMPERATURE_2Buffer *buffer = &memory->temperature_2;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream temperature_3 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_temperature_3(Memory *memory, unsigned int offset) {
  TEMPERATURE_3Buffer *buffer = &memory->temperature_3;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TEMPERATURE_3_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream temperature_3 with a new value.
void memory_update_temperature_3(Memory *memory, float new_value) {

  TEMPERATURE_3Buffer *buffer = &memory->temperature_3;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream voltage_0 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_voltage_0(Memory *memory, unsigned int offset) {
  VOLTAGE_0Buffer *buffer = &memory->voltage_0;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += VOLTAGE_0_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream voltage_0 with a new value.
void memory_update_voltage_0(Memory *memory, float new_value) {

  VOLTAGE_0Buffer *buffer = &memory->voltage_0;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream voltage_1 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_voltage_1(Memory *memory, unsigned int offset) {
  VOLTAGE_1Buffer *buffer = &memory->voltage_1;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += VOLTAGE_1_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream voltage_1 with a new value.
void memory_update_voltage_1(Memory *memory, float new_value) {

  VOLTAGE_1Buffer *buffer = &memory->voltage_1;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream voltage_2 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_voltage_2(Memory *memory, unsigned int offset) {
  VOLTAGE_2Buffer *buffer = &memory->voltage_2;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += VOLTAGE_2_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream voltage_2 with a new value.
void memory_update_voltage_2(Memory *memory, float new_value) {

  VOLTAGE_2Buffer *buffer = &memory->voltage_2;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream current_time with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_current_time(Memory *memory, unsigned int offset) {
  CURRENT_TIMEBuffer *buffer = &memory->current_time;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += CURRENT_TIME_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream current_time with a new value.
void memory_update_current_time(Memory *memory, float new_value) {

  CURRENT_TIMEBuffer *buffer = &memory->current_time;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream diff_vol_0_1 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_diff_vol_0_1(Memory *memory, unsigned int offset) {
  DIFF_VOL_0_1Buffer *buffer = &memory->diff_vol_0_1;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += DIFF_VOL_0_1_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream diff_vol_0_1 with a new value.
void memory_update_diff_vol_0_1(Memory *memory, float new_value) {

  DIFF_VOL_0_1Buffer *buffer = &memory->diff_vol_0_1;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream diff_vol_1_2 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_diff_vol_1_2(Memory *memory, unsigned int offset) {
  DIFF_VOL_1_2Buffer *buffer = &memory->diff_vol_1_2;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += DIFF_VOL_1_2_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream diff_vol_1_2 with a new value.
void memory_update_diff_vol_1_2(Memory *memory, float new_value) {

  DIFF_VOL_1_2Buffer *buffer = &memory->diff_vol_1_2;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream diff_vol_2_0 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_diff_vol_2_0(Memory *memory, unsigned int offset) {
  DIFF_VOL_2_0Buffer *buffer = &memory->diff_vol_2_0;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += DIFF_VOL_2_0_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream diff_vol_2_0 with a new value.
void memory_update_diff_vol_2_0(Memory *memory, float new_value) {

  DIFF_VOL_2_0Buffer *buffer = &memory->diff_vol_2_0;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream consumption with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
float *memory_consumption(Memory *memory, unsigned int offset) {
  CONSUMPTIONBuffer *buffer = &memory->consumption;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += CONSUMPTION_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream consumption with a new value.
void memory_update_consumption(Memory *memory, float new_value) {

  CONSUMPTIONBuffer *buffer = &memory->consumption;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream max_temp with an offset. If the value exists
// a reference to it is given, otherwise None or NULL is returned.
float *memory_max_temp(Memory *memory, unsigned int offset) {
  MAX_TEMPBuffer *buffer = &memory->max_temp;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += MAX_TEMP_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream max_temp with a new value.
void memory_update_max_temp(Memory *memory, float new_value) {

  MAX_TEMPBuffer *buffer = &memory->max_temp;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream trigger_0 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
int *memory_trigger_0(Memory *memory, unsigned int offset) {
  TRIGGER_0Buffer *buffer = &memory->trigger_0;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TRIGGER_0_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream trigger_0 with a new value.
void memory_update_trigger_0(Memory *memory, int new_value) {

  TRIGGER_0Buffer *buffer = &memory->trigger_0;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream trigger_1 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
int *memory_trigger_1(Memory *memory, unsigned int offset) {
  TRIGGER_1Buffer *buffer = &memory->trigger_1;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TRIGGER_1_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream trigger_1 with a new value.
void memory_update_trigger_1(Memory *memory, int new_value) {

  TRIGGER_1Buffer *buffer = &memory->trigger_1;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream trigger_2 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
int *memory_trigger_2(Memory *memory, unsigned int offset) {
  TRIGGER_2Buffer *buffer = &memory->trigger_2;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TRIGGER_2_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream trigger_2 with a new value.
void memory_update_trigger_2(Memory *memory, int new_value) {

  TRIGGER_2Buffer *buffer = &memory->trigger_2;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream trigger_3 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
int *memory_trigger_3(Memory *memory, unsigned int offset) {
  TRIGGER_3Buffer *buffer = &memory->trigger_3;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TRIGGER_3_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream trigger_3 with a new value.
void memory_update_trigger_3(Memory *memory, int new_value) {

  TRIGGER_3Buffer *buffer = &memory->trigger_3;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream trigger_4 with an offset. If the value
// exists a reference to it is given, otherwise None or NULL is returned.
int *memory_trigger_4(Memory *memory, unsigned int offset) {
  TRIGGER_4Buffer *buffer = &memory->trigger_4;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TRIGGER_4_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return NULL;
  }
}
// Updates the stream trigger_4 with a new value.
void memory_update_trigger_4(Memory *memory, int new_value) {

  TRIGGER_4Buffer *buffer = &memory->trigger_4;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}


// --------------------------


// --------------------------


// --------------------------

float current(Memory *memory);
float current_offset(Memory *memory, unsigned int offset, float def);
float temperature_0(Memory *memory);
float temperature_1(Memory *memory);
float temperature_2(Memory *memory);
float temperature_3(Memory *memory);
float voltage_0(Memory *memory);
float voltage_1(Memory *memory);
float voltage_2(Memory *memory);
float current_time(Memory *memory);
float current_time_offset(Memory *memory, unsigned int offset, float def);
float diff_vol_0_1(Memory *memory);
float diff_vol_1_2(Memory *memory);
float diff_vol_2_0(Memory *memory);
float consumption(Memory *memory);
float consumption_offset(Memory *memory, unsigned int offset, float def);
float max_temp(Memory *memory);
int trigger_0(Memory *memory);
int trigger_1(Memory *memory);
int trigger_2(Memory *memory);
int trigger_3(Memory *memory);
int trigger_4(Memory *memory);


// -- current -------

// Add a new value to the memory of the stream current.
//
// RtLola definition: input current : Float32
void eval_current(Memory *memory, float new_value) {
  memory_update_current(memory, new_value);
}

// Allows access to the stream current with an offset access.
//
// RtLola expression: current.offset(by:-`offset`).default(to: `default`)
float current_offset(Memory *memory, unsigned int offset, float def) {
  float *value = memory_current(memory, offset);
  if(value != NULL) {
    return *value;
  } else {
    return def;
  }
}


// Allows synchronous access to the stream current.
//
// RtLola expression: current
float current(Memory *memory) {
  float *value = memory_current(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream current to make room for a new
// value.
//
// Pseudo evaluation is needed because stream current has a size of 2 (>1).
void shift_current(Memory *memory) {
  CURRENTBuffer *buffer = &memory->current;
  buffer->current = (buffer->current + 1) % CURRENT_SIZE;
}
// -------

// -- temperature_0 -------

// Add a new value to the memory of the stream temperature_0.
//
// RtLola definition: input temperature_0 : Float32
void eval_temperature_0(Memory *memory, float new_value) {
  memory_update_temperature_0(memory, new_value);
}

// Allows synchronous access to the stream temperature_0.
//
// RtLola expression: temperature_0
float temperature_0(Memory *memory) {
  float *value = memory_temperature_0(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream temperature_0 to make room for
// a new value.
//
// Pseudo evaluation is needed because stream temperature_0 has a size of 1
// (>1).
void shift_temperature_0(Memory *memory) {
  TEMPERATURE_0Buffer *buffer = &memory->temperature_0;
  buffer->current = (buffer->current + 1) % TEMPERATURE_0_SIZE;
}
// -------

// -- temperature_1 -------

// Add a new value to the memory of the stream temperature_1.
//
// RtLola definition: input temperature_1 : Float32
void eval_temperature_1(Memory *memory, float new_value) {
  memory_update_temperature_1(memory, new_value);
}

// Allows synchronous access to the stream temperature_1.
//
// RtLola expression: temperature_1
float temperature_1(Memory *memory) {
  float *value = memory_temperature_1(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream temperature_1 to make room for
// a new value.
//
// Pseudo evaluation is needed because stream temperature_1 has a size of 1
// (>1).
void shift_temperature_1(Memory *memory) {
  TEMPERATURE_1Buffer *buffer = &memory->temperature_1;
  buffer->current = (buffer->current + 1) % TEMPERATURE_1_SIZE;
}
// -------

// -- temperature_2 -------

// Add a new value to the memory of the stream temperature_2.
//
// RtLola definition: input temperature_2 : Float32
void eval_temperature_2(Memory *memory, float new_value) {
  memory_update_temperature_2(memory, new_value);
}

// Allows synchronous access to the stream temperature_2.
//
// RtLola expression: temperature_2
float temperature_2(Memory *memory) {
  float *value = memory_temperature_2(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream temperature_2 to make room for
// a new value.
//
// Pseudo evaluation is needed because stream temperature_2 has a size of 1
// (>1).
void shift_temperature_2(Memory *memory) {
  TEMPERATURE_2Buffer *buffer = &memory->temperature_2;
  buffer->current = (buffer->current + 1) % TEMPERATURE_2_SIZE;
}
// -------

// -- temperature_3 -------

// Add a new value to the memory of the stream temperature_3.
//
// RtLola definition: input temperature_3 : Float32
void eval_temperature_3(Memory *memory, float new_value) {
  memory_update_temperature_3(memory, new_value);
}

// Allows synchronous access to the stream temperature_3.
//
// RtLola expression: temperature_3
float temperature_3(Memory *memory) {
  float *value = memory_temperature_3(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream temperature_3 to make room for
// a new value.
//
// Pseudo evaluation is needed because stream temperature_3 has a size of 1
// (>1).
void shift_temperature_3(Memory *memory) {
  TEMPERATURE_3Buffer *buffer = &memory->temperature_3;
  buffer->current = (buffer->current + 1) % TEMPERATURE_3_SIZE;
}
// -------

// -- voltage_0 -------

// Add a new value to the memory of the stream voltage_0.
//
// RtLola definition: input voltage_0 : Float32
void eval_voltage_0(Memory *memory, float new_value) {
  memory_update_voltage_0(memory, new_value);
}

// Allows synchronous access to the stream voltage_0.
//
// RtLola expression: voltage_0
float voltage_0(Memory *memory) {
  float *value = memory_voltage_0(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream voltage_0 to make room for a
// new value.
//
// Pseudo evaluation is needed because stream voltage_0 has a size of 1 (>1).
void shift_voltage_0(Memory *memory) {
  VOLTAGE_0Buffer *buffer = &memory->voltage_0;
  buffer->current = (buffer->current + 1) % VOLTAGE_0_SIZE;
}
// -------

// -- voltage_1 -------

// Add a new value to the memory of the stream voltage_1.
//
// RtLola definition: input voltage_1 : Float32
void eval_voltage_1(Memory *memory, float new_value) {
  memory_update_voltage_1(memory, new_value);
}

// Allows synchronous access to the stream voltage_1.
//
// RtLola expression: voltage_1
float voltage_1(Memory *memory) {
  float *value = memory_voltage_1(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream voltage_1 to make room for a
// new value.
//
// Pseudo evaluation is needed because stream voltage_1 has a size of 1 (>1).
void shift_voltage_1(Memory *memory) {
  VOLTAGE_1Buffer *buffer = &memory->voltage_1;
  buffer->current = (buffer->current + 1) % VOLTAGE_1_SIZE;
}
// -------

// -- voltage_2 -------

// Add a new value to the memory of the stream voltage_2.
//
// RtLola definition: input voltage_2 : Float32
void eval_voltage_2(Memory *memory, float new_value) {
  memory_update_voltage_2(memory, new_value);
}

// Allows synchronous access to the stream voltage_2.
//
// RtLola expression: voltage_2
float voltage_2(Memory *memory) {
  float *value = memory_voltage_2(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream voltage_2 to make room for a
// new value.
//
// Pseudo evaluation is needed because stream voltage_2 has a size of 1 (>1).
void shift_voltage_2(Memory *memory) {
  VOLTAGE_2Buffer *buffer = &memory->voltage_2;
  buffer->current = (buffer->current + 1) % VOLTAGE_2_SIZE;
}
// -------

// -- current_time -------

// Add a new value to the memory of the stream current_time.
//
// RtLola definition: input current_time : Float32
void eval_current_time(Memory *memory, float new_value) {
  memory_update_current_time(memory, new_value);
}

// Allows access to the stream current_time with an offset access.
//
// RtLola expression: current_time.offset(by:-`offset`).default(to: `default`)
float current_time_offset(Memory *memory, unsigned int offset, float def) {
  float *value = memory_current_time(memory, offset);
  if(value != NULL) {
    return *value;
  } else {
    return def;
  }
}


// Allows synchronous access to the stream current_time.
//
// RtLola expression: current_time
float current_time(Memory *memory) {
  float *value = memory_current_time(memory, 0);
  return *value;
}

// Shifts all the values in the buffer of stream current_time to make room for a
// new value.
//
// Pseudo evaluation is needed because stream current_time has a size of 2 (>1).
void shift_current_time(Memory *memory) {
  CURRENT_TIMEBuffer *buffer = &memory->current_time;
  buffer->current = (buffer->current + 1) % CURRENT_TIME_SIZE;
}


// --------------------------


// -- diff_vol_0_1 -------

// Allows synchronous access to the stream diff_vol_0_1.
//
// RtLola expression: diff_vol_0_1
float diff_vol_0_1(Memory *memory) {
  float *value = memory_diff_vol_0_1(memory, 0);
  return *value;
}

// Calculate the current value of the stream diff_vol_0_1.
//
// RtLola definition: output diff_vol_0_1 @(voltage_0∧voltage_1) : Float32 :=
// fabs(voltage_0 - voltage_1
void eval_diff_vol_0_1(Memory *memory) {
  // voltage_0 : Float32
  float sync_access0 = ((float)voltage_0(memory));
  // voltage_1 : Float32
  float sync_access1 = ((float)voltage_1(memory));
  // voltage_0 - voltage_1 : Float32
  float binop0 = (sync_access0 - sync_access1);
  // fabs(voltage_0 - voltage_1 : Float32
  float new_value = fabs(binop0);
  memory_update_diff_vol_0_1(memory, new_value);
}
// -------

// -- diff_vol_1_2 -------

// Allows synchronous access to the stream diff_vol_1_2.
//
// RtLola expression: diff_vol_1_2
float diff_vol_1_2(Memory *memory) {
  float *value = memory_diff_vol_1_2(memory, 0);
  return *value;
}

// Calculate the current value of the stream diff_vol_1_2.
//
// RtLola definition: output diff_vol_1_2 @(voltage_1∧voltage_2) : Float32 :=
// fabs(voltage_1 - voltage_2
void eval_diff_vol_1_2(Memory *memory) {
  // voltage_1 : Float32
  float sync_access0 = ((float)voltage_1(memory));
  // voltage_2 : Float32
  float sync_access1 = ((float)voltage_2(memory));
  // voltage_1 - voltage_2 : Float32
  float binop0 = (sync_access0 - sync_access1);
  // fabs(voltage_1 - voltage_2 : Float32
  float new_value = fabs(binop0);
  memory_update_diff_vol_1_2(memory, new_value);
}
// -------

// -- diff_vol_2_0 -------

// Allows synchronous access to the stream diff_vol_2_0.
//
// RtLola expression: diff_vol_2_0
float diff_vol_2_0(Memory *memory) {
  float *value = memory_diff_vol_2_0(memory, 0);
  return *value;
}

// Calculate the current value of the stream diff_vol_2_0.
//
// RtLola definition: output diff_vol_2_0 @(voltage_0∧voltage_2) : Float32 :=
// fabs(voltage_2 - voltage_0
void eval_diff_vol_2_0(Memory *memory) {
  // voltage_2 : Float32
  float sync_access0 = ((float)voltage_2(memory));
  // voltage_0 : Float32
  float sync_access1 = ((float)voltage_0(memory));
  // voltage_2 - voltage_0 : Float32
  float binop0 = (sync_access0 - sync_access1);
  // fabs(voltage_2 - voltage_0 : Float32
  float new_value = fabs(binop0);
  memory_update_diff_vol_2_0(memory, new_value);
}
// -------

// -- consumption -------

// Allows access to the stream consumption with an offset access.
//
// RtLola expression: consumption.offset(by:-`offset`).default(to: `default`)
float consumption_offset(Memory *memory, unsigned int offset, float def) {
  float *value = memory_consumption(memory, offset);
  if(value != NULL) {
    return *value;
  } else {
    return def;
  }
}


// Shifts all the values in the buffer of stream consumption to make room for a
// new value.
//
// Pseudo evaluation is needed because stream consumption has a size of 2 (>1).
void shift_consumption(Memory *memory) {
  CONSUMPTIONBuffer *buffer = &memory->consumption;
  buffer->current = (buffer->current + 1) % CONSUMPTION_SIZE;
}

// Allows synchronous access to the stream consumption.
//
// RtLola expression: consumption
float consumption(Memory *memory) {
  float *value = memory_consumption(memory, 0);
  return *value;
}

// Calculate the current value of the stream consumption.
//
// RtLola definition: output consumption @(current∧current_time) : Float32 :=
// 0.5 * (current.offset(by:-1).defaults(to:current) + current) * (current_time
// - current_time.offset(by:-1).defaults(to:current_time)) +
// consumption.offset(by:-1).defaults(to:0)
void eval_consumption(Memory *memory) {
  // 0.5 : Float32
  float const0 = ((float)0.5);
  // current.offset(by:-1).defaults(to:current) : Float32
  float offset_access0 =
      ((float)current_offset(memory, 1, ((float)current(memory))));
  // current : Float32
  float sync_access0 = ((float)current(memory));
  // current.offset(by:-1).defaults(to:current) + current : Float32
  float binop0 = (offset_access0 + sync_access0);
  // 0.5 * (current.offset(by:-1).defaults(to:current) + current) : Float32
  float binop1 = (const0 * binop0);
  // current_time : Float32
  float sync_access1 = ((float)current_time(memory));
  // current_time.offset(by:-1).defaults(to:current_time) : Float32
  float offset_access1 =
      ((float)current_time_offset(memory, 1, ((float)current_time(memory))));
  // current_time - current_time.offset(by:-1).defaults(to:current_time) :
  // Float32
  float binop2 = (sync_access1 - offset_access1);
  // 0.5 * (current.offset(by:-1).defaults(to:current) + current) *
  // (current_time - current_time.offset(by:-1).defaults(to:current_time)) :
  // Float32
  float binop3 = (binop1 * binop2);
  // consumption.offset(by:-1).defaults(to:0) : Float32
  float offset_access2 = ((float)consumption_offset(memory, 1, ((float)0)));
  // 0.5 * (current.offset(by:-1).defaults(to:current) + current) *
  // (current_time - current_time.offset(by:-1).defaults(to:current_time)) +
  // consumption.offset(by:-1).defaults(to:0) : Float32
  float new_value = (binop3 + offset_access2);
  memory_update_consumption(memory, new_value);
}
// -------

// -- max_temp -------

// Allows synchronous access to the stream max_temp.
//
// RtLola expression: max_temp
float max_temp(Memory *memory) {
  float *value = memory_max_temp(memory, 0);
  return *value;
}

// Calculate the current value of the stream max_temp.
//
// RtLola definition: output max_temp
// @(temperature_0∧temperature_1∧temperature_2∧temperature_3) : Float32 :=
// fmax(fmax(temperature_0, temperature_1, fmax(temperature_2, temperature_3
void eval_max_temp(Memory *memory) {
  // temperature_0 : Float32
  float sync_access0 = ((float)temperature_0(memory));
  // temperature_1 : Float32
  float sync_access1 = ((float)temperature_1(memory));
  // fmax(temperature_0, temperature_1 : Float32
  float function0 = fmax(sync_access0, sync_access1);
  // temperature_2 : Float32
  float sync_access2 = ((float)temperature_2(memory));
  // temperature_3 : Float32
  float sync_access3 = ((float)temperature_3(memory));
  // fmax(temperature_2, temperature_3 : Float32
  float function1 = fmax(sync_access2, sync_access3);
  // fmax(fmax(temperature_0, temperature_1, fmax(temperature_2, temperature_3 :
  // Float32
  float new_value = fmax(function0, function1);
  memory_update_max_temp(memory, new_value);
}
// -------

// -- trigger_0 -------

// Allows synchronous access to the stream trigger_0.
//
// RtLola expression: trigger_0
int trigger_0(Memory *memory) {
  int *value = memory_trigger_0(memory, 0);
  return *value;
}

// Calculate the current value of the stream trigger_0.
//
// RtLola definition: output trigger_0 @(voltage_0∧voltage_1∧voltage_2) : Bool
// := diff_vol_0_1 > 0.03 ∨ diff_vol_1_2 > 0.03 ∨ diff_vol_2_0 > 0.03
void eval_trigger_0(Memory *memory) {
  // diff_vol_0_1 : Float32
  float sync_access0 = ((float)diff_vol_0_1(memory));
  // 0.03 : Float32
  float const0 = ((float)0.03);
  // diff_vol_0_1 > 0.03 : Bool
  int binop0 = (sync_access0 > const0);
  // diff_vol_1_2 : Float32
  float sync_access1 = ((float)diff_vol_1_2(memory));
  // 0.03 : Float32
  float const1 = ((float)0.03);
  // diff_vol_1_2 > 0.03 : Bool
  int binop1 = (sync_access1 > const1);
  // diff_vol_0_1 > 0.03 ∨ diff_vol_1_2 > 0.03 : Bool
  int binop2 = (binop0 || binop1);
  // diff_vol_2_0 : Float32
  float sync_access2 = ((float)diff_vol_2_0(memory));
  // 0.03 : Float32
  float const2 = ((float)0.03);
  // diff_vol_2_0 > 0.03 : Bool
  int binop3 = (sync_access2 > const2);
  // diff_vol_0_1 > 0.03 ∨ diff_vol_1_2 > 0.03 ∨ diff_vol_2_0 > 0.03 : Bool
  int new_value = (binop2 || binop3);
  memory_update_trigger_0(memory, new_value);
}
// -------

// -- trigger_1 -------

// Allows synchronous access to the stream trigger_1.
//
// RtLola expression: trigger_1
int trigger_1(Memory *memory) {
  int *value = memory_trigger_1(memory, 0);
  return *value;
}

// Calculate the current value of the stream trigger_1.
//
// RtLola definition: output trigger_1 @(voltage_0∧voltage_1∧voltage_2) : Bool
// := voltage_0 < 3 ∨ voltage_1 < 3 ∨ voltage_2 < 3
void eval_trigger_1(Memory *memory) {
  // voltage_0 : Float32
  float sync_access0 = ((float)voltage_0(memory));
  // 3 : Float32
  float const0 = ((float)3);
  // voltage_0 < 3 : Bool
  int binop0 = (sync_access0 < const0);
  // voltage_1 : Float32
  float sync_access1 = ((float)voltage_1(memory));
  // 3 : Float32
  float const1 = ((float)3);
  // voltage_1 < 3 : Bool
  int binop1 = (sync_access1 < const1);
  // voltage_0 < 3 ∨ voltage_1 < 3 : Bool
  int binop2 = (binop0 || binop1);
  // voltage_2 : Float32
  float sync_access2 = ((float)voltage_2(memory));
  // 3 : Float32
  float const2 = ((float)3);
  // voltage_2 < 3 : Bool
  int binop3 = (sync_access2 < const2);
  // voltage_0 < 3 ∨ voltage_1 < 3 ∨ voltage_2 < 3 : Bool
  int new_value = (binop2 || binop3);
  memory_update_trigger_1(memory, new_value);
}
// -------

// -- trigger_2 -------

// Allows synchronous access to the stream trigger_2.
//
// RtLola expression: trigger_2
int trigger_2(Memory *memory) {
  int *value = memory_trigger_2(memory, 0);
  return *value;
}

// Calculate the current value of the stream trigger_2.
//
// RtLola definition: output trigger_2 @(current) : Bool := current > 45
void eval_trigger_2(Memory *memory) {
  // current : Float32
  float sync_access0 = ((float)current(memory));
  // 45 : Float32
  float const0 = ((float)45);
  // current > 45 : Bool
  int new_value = (sync_access0 > const0);
  memory_update_trigger_2(memory, new_value);
}
// -------

// -- trigger_3 -------

// Allows synchronous access to the stream trigger_3.
//
// RtLola expression: trigger_3
int trigger_3(Memory *memory) {
  int *value = memory_trigger_3(memory, 0);
  return *value;
}

// Calculate the current value of the stream trigger_3.
//
// RtLola definition: output trigger_3 @(current∧current_time) : Bool :=
// consumption > 3
void eval_trigger_3(Memory *memory) {
  // consumption : Float32
  float sync_access0 = ((float)consumption(memory));
  // 3 : Float32
  float const0 = ((float)3);
  // consumption > 3 : Bool
  int new_value = (sync_access0 > const0);
  memory_update_trigger_3(memory, new_value);
}
// -------

// -- trigger_4 -------

// Allows synchronous access to the stream trigger_4.
//
// RtLola expression: trigger_4
int trigger_4(Memory *memory) {
  int *value = memory_trigger_4(memory, 0);
  return *value;
}

// Calculate the current value of the stream trigger_4.
//
// RtLola definition: output trigger_4
// @(temperature_0∧temperature_1∧temperature_2∧temperature_3) : Bool := max_temp
// > 60
void eval_trigger_4(Memory *memory) {
  // max_temp : Float32
  float sync_access0 = ((float)max_temp(memory));
  // 60 : Float32
  float const0 = ((float)60);
  // max_temp > 60 : Bool
  int new_value = (sync_access0 > const0);
  memory_update_trigger_4(memory, new_value);
}


// --------------------------


// Checks the trigger condition of trigger trigger_0.
//
// RtLola Definition: trigger trigger_0 "trigger0"
int check_trigger_0(Memory *memory) {
  if(*memory_trigger_0(memory, 0)) {
    return 1;
  }
  return 0;
}
// -------


// Checks the trigger condition of trigger trigger_1.
//
// RtLola Definition: trigger trigger_1 "trigger1"
int check_trigger_1(Memory *memory) {
  if(*memory_trigger_1(memory, 0)) {
    return 1;
  }
  return 0;
}
// -------


// Checks the trigger condition of trigger trigger_2.
//
// RtLola Definition: trigger trigger_2 "trigger2"
int check_trigger_2(Memory *memory) {
  if(*memory_trigger_2(memory, 0)) {
    return 1;
  }
  return 0;
}
// -------


// Checks the trigger condition of trigger trigger_3.
//
// RtLola Definition: trigger trigger_3 "trigger3"
int check_trigger_3(Memory *memory) {
  if(*memory_trigger_3(memory, 0)) {
    return 1;
  }
  return 0;
}
// -------


// Checks the trigger condition of trigger trigger_4.
//
// RtLola Definition: trigger trigger_4 "trigger4"
int check_trigger_4(Memory *memory) {
  if(*memory_trigger_4(memory, 0)) {
    return 1;
  }
  return 0;
}


// ########################
// #      INTERFACE       #
// ########################

// Updates all the input streams that get new values from an event.
// Also does pseudo-evaluation of all output streams that need that.
//
// Input streams: current, temperature_0, temperature_1, temperature_2,
// temperature_3, voltage_0, voltage_1, voltage_2, current_time Pseudo
// evaluation: consumption
void layer0(Memory *memory, Event *event) {
  shift_current(memory);
  eval_current(memory, event->current);
  eval_temperature_0(memory, event->temperature_0);
  eval_temperature_1(memory, event->temperature_1);
  eval_temperature_2(memory, event->temperature_2);
  eval_temperature_3(memory, event->temperature_3);
  eval_voltage_0(memory, event->voltage_0);
  eval_voltage_1(memory, event->voltage_1);
  eval_voltage_2(memory, event->voltage_2);
  shift_current_time(memory);
  eval_current_time(memory, memory->time);
  shift_consumption(memory);
}

// Checks and updates all the output streams on layer 1
//
// Streams on layer 1: diff_vol_0_1, diff_vol_1_2, diff_vol_2_0, consumption,
// max_temp, trigger_1, trigger_2
void layer1(Memory *memory, Event *event) {
  eval_diff_vol_0_1(memory);
  eval_diff_vol_1_2(memory);
  eval_diff_vol_2_0(memory);
  eval_consumption(memory);
  eval_max_temp(memory);
  eval_trigger_1(memory);
  eval_trigger_2(memory);
}

// Checks and updates all the output streams on layer 2
//
// Streams on layer 2: trigger_0, trigger_3, trigger_4
void layer2(Memory *memory, Event *event) {
  eval_trigger_0(memory);
  eval_trigger_3(memory);
  eval_trigger_4(memory);
}

// Checks all the triggers that are due given an event.
TriggerResults trigger_layer(Memory *memory, Event *event) {
  int trigger0 = check_trigger_0(memory);
  int trigger1 = check_trigger_1(memory);
  int trigger2 = check_trigger_2(memory);
  int trigger3 = check_trigger_3(memory);
  int trigger4 = check_trigger_4(memory);
  return (TriggerResults) {trigger0, trigger1, trigger2, trigger3, trigger4};
}

Memory lola_init() {
    Memory memory;
    memset(&memory, 0, sizeof(memory));
    return memory;
}

TriggerResults lola_monitor(Memory *memory, Event event, float time) {
    memory->time = time;

  // 2 Layers:
  //   0. Layer (inputs & pseudo evaluation):
  //   - current
  //   - temperature_0
  //   - temperature_1
  //   - temperature_2
  //   - temperature_3
  //   - voltage_0
  //   - voltage_1
  //   - voltage_2
  //   - current_time
  //   1. Layer:
  //   - diff_vol_0_1
  //   - diff_vol_1_2
  //   - diff_vol_2_0
  //   - consumption
  //   - max_temp
  //   - trigger_1
  //   - trigger_2
  //   2. Layer:
  //   - trigger_0
  //   - trigger_3
  //   - trigger_4

  layer0(memory, &event);
  layer1(memory, &event);
  layer2(memory, &event);
  return trigger_layer(memory, &event);
}
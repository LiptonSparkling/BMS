//
// ------------------------------------------
// Compiled with rtlola-compiler version 0.1.0
// user: frederik
// at:   2023-06-01 10:31:43.811073583 +02:00
// ------------------------------------------
// configuration:
//     input file: /home/frederik/work/rtlola-compiler/crates/battery.lola
//     Code-Formatter:        C-Offline
//     Annotation-Formatter:  description-annotation-formatter +
//     traceability-annotations Interface:             CSVInterface Debug
//     Functions:       false
// ------------------------------------------
// produced the following files:
// - output.TODO.c
// ------------------------------------------

// ########################
// #       STREAMS        #
// ########################

// The memory of stream voltage_1 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "voltage_1" of type Float32.
// Memory bound 1 because it is accessed by similar_1_2 with "Sync".
// All accesses to this stream:
// - similar_1_2 with "Sync"
// - similar_3_1 with "Sync"
#define VOLTAGE_1_SIZE 1
typedef struct {
  float values[VOLTAGE_1_SIZE];
  int valid[VOLTAGE_1_SIZE];
  unsigned int current;
} Voltage_1Buffer;

// The memory of stream voltage_2 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "voltage_2" of type Float32.
// Memory bound 1 because it is accessed by similar_1_2 with "Sync".
// All accesses to this stream:
// - similar_1_2 with "Sync"
// - similar_2_3 with "Sync"
#define VOLTAGE_2_SIZE 1
typedef struct {
  float values[VOLTAGE_2_SIZE];
  int valid[VOLTAGE_2_SIZE];
  unsigned int current;
} Voltage_2Buffer;

// The memory of stream voltage_3 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "voltage_3" of type Float32.
// Memory bound 1 because it is accessed by similar_2_3 with "Sync".
// All accesses to this stream:
// - similar_2_3 with "Sync"
// - similar_3_1 with "Sync"
#define VOLTAGE_3_SIZE 1
typedef struct {
  float values[VOLTAGE_3_SIZE];
  int valid[VOLTAGE_3_SIZE];
  unsigned int current;
} Voltage_3Buffer;

// The memory of stream similar_1_2 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "similar_1_2" of type Bool.
// Memory bound 1 because it is accessed by trigger_0 with "Sync".
// All accesses to this stream:
// - trigger_0 with "Sync"
#define SIMILAR_1_2_SIZE 1
typedef struct {
  int values[SIMILAR_1_2_SIZE];
  int valid[SIMILAR_1_2_SIZE];
  unsigned int current;
} Similar_1_2Buffer;

// The memory of stream similar_2_3 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "similar_2_3" of type Bool.
// Memory bound 1 because it is accessed by trigger_0 with "Sync".
// All accesses to this stream:
// - trigger_0 with "Sync"
#define SIMILAR_2_3_SIZE 1
typedef struct {
  int values[SIMILAR_2_3_SIZE];
  int valid[SIMILAR_2_3_SIZE];
  unsigned int current;
} Similar_2_3Buffer;

// The memory of stream similar_3_1 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "similar_3_1" of type Bool.
// Memory bound 1 because it is accessed by trigger_0 with "Sync".
// All accesses to this stream:
// - trigger_0 with "Sync"
#define SIMILAR_3_1_SIZE 1
typedef struct {
  int values[SIMILAR_3_1_SIZE];
  int valid[SIMILAR_3_1_SIZE];
  unsigned int current;
} Similar_3_1Buffer;

// The memory of stream trigger_0 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "trigger_0" of type Bool.
// All accesses to this stream:
#define TRIGGER_0_SIZE 1
typedef struct {
  int values[TRIGGER_0_SIZE];
  int valid[TRIGGER_0_SIZE];
  unsigned int current;
} Trigger_0Buffer;

// The memory consists of memory for each stream and each sliding window.
typedef struct {
  // current_time
  double time;
  // Streams
  Voltage_1Buffer voltage_1;
  Voltage_2Buffer voltage_2;
  Voltage_3Buffer voltage_3;
  Similar_1_2Buffer similar_1_2;
  Similar_2_3Buffer similar_2_3;
  Similar_3_1Buffer similar_3_1;
  Trigger_0Buffer trigger_0;
} Memory;

// Accesses the value of the stream voltage_1 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
float *memory_voltage_1(Memory *memory, unsigned int offset) {
  Voltage_1Buffer *buffer = &memory->voltage_1;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += VOLTAGE_1_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }
}
// Updates the stream voltage_1 with a new value.
void memory_update_voltage_1(Memory *memory, float new_value) {
  Voltage_1Buffer *buffer = &memory->voltage_1;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream voltage_2 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
float *memory_voltage_2(Memory *memory, unsigned int offset) {
  Voltage_2Buffer *buffer = &memory->voltage_2;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += VOLTAGE_2_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }
}
// Updates the stream voltage_2 with a new value.
void memory_update_voltage_2(Memory *memory, float new_value) {
  Voltage_2Buffer *buffer = &memory->voltage_2;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream voltage_3 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
float *memory_voltage_3(Memory *memory, unsigned int offset) {
  Voltage_3Buffer *buffer = &memory->voltage_3;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += VOLTAGE_3_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }
}

// Updates the stream voltage_3 with a new value.
void memory_update_voltage_3(Memory *memory, float new_value) {
  Voltage_3Buffer *buffer = &memory->voltage_3;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream similar_1_2 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
int *memory_similar_1_2(Memory *memory, unsigned int offset) {
  Similar_1_2Buffer *buffer = &memory->similar_1_2;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += SIMILAR_1_2_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }
}

// Updates the stream similar_1_2 with a new value.
void memory_update_similar_1_2(Memory *memory, int new_value) {
  Similar_1_2Buffer *buffer = &memory->similar_1_2;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream similar_2_3 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
int *memory_similar_2_3(Memory *memory, unsigned int offset) {
  Similar_2_3Buffer *buffer = &memory->similar_2_3;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += SIMILAR_2_3_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }
}

// Updates the stream similar_2_3 with a new value.
void memory_update_similar_2_3(Memory *memory, int new_value) {
  Similar_2_3Buffer *buffer = &memory->similar_2_3;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream similar_3_1 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
int *memory_similar_3_1(Memory *memory, unsigned int offset) {
  Similar_3_1Buffer *buffer = &memory->similar_3_1;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += SIMILAR_3_1_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }

}
// Updates the stream similar_3_1 with a new value.
void memory_update_similar_3_1(Memory *memory, int new_value) {
  Similar_3_1Buffer *buffer = &memory->similar_3_1;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// Accesses the value of the stream trigger_0 with an offset. If the value
// exists a reference to it is given, otherwise None or 0 is returned.
int *memory_trigger_0(Memory *memory, unsigned int offset) {
  Trigger_0Buffer *buffer = &memory->trigger_0;
  int index = (int)buffer->current;
  index -= offset;
  if(index < 0)
    index += TRIGGER_0_SIZE;
  if(buffer->valid[index]) {
    return buffer->values + index;
  } else {
    return 0;
  }
}

// Updates the stream trigger_0 with a new value.
void memory_update_trigger_0(Memory *memory, int new_value) {
  Trigger_0Buffer *buffer = &memory->trigger_0;
  buffer->values[buffer->current] = new_value;
  buffer->valid[buffer->current] = 1;
}

// --------------------------

float voltage_1(Memory *memory);
float voltage_2(Memory *memory);
float voltage_3(Memory *memory);
int similar_1_2(Memory *memory);
int similar_2_3(Memory *memory);
int similar_3_1(Memory *memory);
int trigger_0(Memory *memory);

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

// -- voltage_3 -------

// Add a new value to the memory of the stream voltage_3.
//
// RtLola definition: input voltage_3 : Float32
void eval_voltage_3(Memory *memory, float new_value) {
  memory_update_voltage_3(memory, new_value);
}

// Allows synchronous access to the stream voltage_3.
//
// RtLola expression: voltage_3
float voltage_3(Memory *memory) {
  float *value = memory_voltage_3(memory, 0);

  return *value;
}

// -- similar_1_2 -------

// Allows synchronous access to the stream similar_1_2.
//
// RtLola expression: similar_1_2
int similar_1_2(Memory *memory) {
  int *value = memory_similar_1_2(memory, 0);

  return *value;
}

// Calculate the current value of the stream similar_1_2.
//
// RtLola definition: output similar_1_2 @(voltage_1∧voltage_2) : Bool :=
// voltage_1 - voltage_1 * 0.03 ≤ voltage_2 ∧ voltage_2 ≤ voltage_1 + voltage_1
// * 0.03
void eval_similar_1_2(Memory *memory) {
  // voltage_1 : Float32
  float sync_access0 = (voltage_1(memory));
  // voltage_1 : Float32
  float sync_access1 = (voltage_1(memory));
  // 0.03 : Float32
  float const0 = (0.03);
  // voltage_1 * 0.03 : Float32
  float binop0 = (sync_access1 * const0);
  // voltage_1 - voltage_1 * 0.03 : Float32
  float binop1 = (sync_access0 - binop0);
  // voltage_2 : Float32
  float sync_access2 = (voltage_2(memory));
  // voltage_1 - voltage_1 * 0.03 ≤ voltage_2 : Bool
  int binop2 = (binop1 <= sync_access2);
  // voltage_2 : Float32
  float sync_access3 = (voltage_2(memory));
  // voltage_1 : Float32
  float sync_access4 = (voltage_1(memory));
  // voltage_1 : Float32
  float sync_access5 = (voltage_1(memory));
  // 0.03 : Float32
  float const1 = (0.03);
  // voltage_1 * 0.03 : Float32
  float binop3 = (sync_access5 * const1);
  // voltage_1 + voltage_1 * 0.03 : Float32
  float binop4 = (sync_access4 + binop3);
  // voltage_2 ≤ voltage_1 + voltage_1 * 0.03 : Bool
  int binop5 = (sync_access3 <= binop4);
  // voltage_1 - voltage_1 * 0.03 ≤ voltage_2 ∧ voltage_2 ≤ voltage_1 +
  // voltage_1 * 0.03 : Bool
  int new_value = (binop2 && binop5);
  memory_update_similar_1_2(memory, new_value);
}

// -- similar_2_3 -------

// Allows synchronous access to the stream similar_2_3.
//
// RtLola expression: similar_2_3
int similar_2_3(Memory *memory) {
  int *value = memory_similar_2_3(memory, 0);

  return *value;
}

// Calculate the current value of the stream similar_2_3.
//
// RtLola definition: output similar_2_3 @(voltage_2∧voltage_3) : Bool :=
// voltage_2 - voltage_2 * 0.03 ≤ voltage_3 ∧ voltage_3 ≤ voltage_2 + voltage_2
// * 0.03
void eval_similar_2_3(Memory *memory) {
  // voltage_2 : Float32
  float sync_access0 = (voltage_2(memory));
  // voltage_2 : Float32
  float sync_access1 = (voltage_2(memory));
  // 0.03 : Float32
  float const0 = (0.03);
  // voltage_2 * 0.03 : Float32
  float binop0 = (sync_access1 * const0);
  // voltage_2 - voltage_2 * 0.03 : Float32
  float binop1 = (sync_access0 - binop0);
  // voltage_3 : Float32
  float sync_access2 = (voltage_3(memory));
  // voltage_2 - voltage_2 * 0.03 ≤ voltage_3 : Bool
  int binop2 = (binop1 <= sync_access2);
  // voltage_3 : Float32
  float sync_access3 = (voltage_3(memory));
  // voltage_2 : Float32
  float sync_access4 = (voltage_2(memory));
  // voltage_2 : Float32
  float sync_access5 = (voltage_2(memory));
  // 0.03 : Float32
  float const1 = (0.03);
  // voltage_2 * 0.03 : Float32
  float binop3 = (sync_access5 * const1);
  // voltage_2 + voltage_2 * 0.03 : Float32
  float binop4 = (sync_access4 + binop3);
  // voltage_3 ≤ voltage_2 + voltage_2 * 0.03 : Bool
  int binop5 = (sync_access3 <= binop4);
  // voltage_2 - voltage_2 * 0.03 ≤ voltage_3 ∧ voltage_3 ≤ voltage_2 +
  // voltage_2 * 0.03 : Bool
  int new_value = (binop2 && binop5);
  memory_update_similar_2_3(memory, new_value);
}

// -- similar_3_1 -------

// Allows synchronous access to the stream similar_3_1.
//
// RtLola expression: similar_3_1
int similar_3_1(Memory *memory) {
  int *value = memory_similar_3_1(memory, 0);

  return *value;
}

// Calculate the current value of the stream similar_3_1.
//
// RtLola definition: output similar_3_1 @(voltage_1∧voltage_3) : Bool :=
// voltage_3 - voltage_3 * 0.03 ≤ voltage_1 ∧ voltage_1 ≤ voltage_3 + voltage_3
// * 0.03
void eval_similar_3_1(Memory *memory) {
  // voltage_3 : Float32
  float sync_access0 = (voltage_3(memory));
  // voltage_3 : Float32
  float sync_access1 = (voltage_3(memory));
  // 0.03 : Float32
  float const0 = (0.03);
  // voltage_3 * 0.03 : Float32
  float binop0 = (sync_access1 * const0);
  // voltage_3 - voltage_3 * 0.03 : Float32
  float binop1 = (sync_access0 - binop0);
  // voltage_1 : Float32
  float sync_access2 = (voltage_1(memory));
  // voltage_3 - voltage_3 * 0.03 ≤ voltage_1 : Bool
  int binop2 = (binop1 <= sync_access2);
  // voltage_1 : Float32
  float sync_access3 = (voltage_1(memory));
  // voltage_3 : Float32
  float sync_access4 = (voltage_3(memory));
  // voltage_3 : Float32
  float sync_access5 = (voltage_3(memory));
  // 0.03 : Float32
  float const1 = (0.03);
  // voltage_3 * 0.03 : Float32
  float binop3 = (sync_access5 * const1);
  // voltage_3 + voltage_3 * 0.03 : Float32
  float binop4 = (sync_access4 + binop3);
  // voltage_1 ≤ voltage_3 + voltage_3 * 0.03 : Bool
  int binop5 = (sync_access3 <= binop4);
  // voltage_3 - voltage_3 * 0.03 ≤ voltage_1 ∧ voltage_1 ≤ voltage_3 +
  // voltage_3 * 0.03 : Bool
  int new_value = (binop2 && binop5);
  memory_update_similar_3_1(memory, new_value);
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
// RtLola definition: output trigger_0 @(voltage_1∧voltage_2∧voltage_3) : Bool
// := !(similar_1_2 ∧ similar_2_3 ∧ similar_3_1)
void eval_trigger_0(Memory *memory) {
  // similar_1_2 : Bool
  int sync_access0 = (similar_1_2(memory));
  // similar_2_3 : Bool
  int sync_access1 = (similar_2_3(memory));
  // similar_1_2 ∧ similar_2_3 : Bool
  int binop0 = (sync_access0 && sync_access1);
  // similar_3_1 : Bool
  int sync_access2 = (similar_3_1(memory));
  // similar_1_2 ∧ similar_2_3 ∧ similar_3_1 : Bool
  int binop1 = (binop0 && sync_access2);
  // !(similar_1_2 ∧ similar_2_3 ∧ similar_3_1) : Bool
  int new_value = !binop1;
  memory_update_trigger_0(memory, new_value);
}

// Checks the trigger condition of trigger trigger_0.
//
// RtLola Definition: trigger trigger_0 "Error: Voltage deviation"
int check_trigger0(Memory *memory) {
  if(*memory_trigger_0(memory, 0)) {
    return 1;
  }
  return 0;
}

typedef struct {
    float voltage_1;
    float voltage_2;
    float voltage_3;
} Event;

// Updates all the input streams that get new values from an event.
// Also does pseudo-evaluation of all output streams that need that.
//
// Input streams: voltage_1, voltage_2, voltage_3
void layer0(Memory *memory, Event *event) {
    eval_voltage_1(memory, event->voltage_1);
    eval_voltage_2(memory, event->voltage_2);
    eval_voltage_3(memory, event->voltage_3);
}

// Checks and updates all the output streams on layer 1
//
// Streams on layer 1: similar_1_2, similar_2_3, similar_3_1
void layer1(Memory *memory, Event *event) {
    eval_similar_1_2(memory);
    eval_similar_2_3(memory);
    eval_similar_3_1(memory);
}

// Checks and updates all the output streams on layer 2
//
// Streams on layer 2: trigger_0
void layer2(Memory *memory, Event *event) {
    eval_trigger_0(memory);
}

// Checks all the triggers that are due given an event.
int trigger_layer(Memory *memory, Event *event) {
    return check_trigger0(memory);
}

Memory init() {
    Memory memory;
    memset(&memory, 0, sizeof(memory));
    return memory;
}

int monitor(Memory *memory, Event e, float time) {
    memory->time = time;
  // 2 Layers:
  //   0. Layer (inputs & pseudo evaluation):
  //   - voltage_1
  //   - voltage_2
  //   - voltage_3
  //   1. Layer:
  //   - similar_1_2
  //   - similar_2_3
  //   - similar_3_1
  //   2. Layer:
  //   - trigger_0

  layer0(memory, &e);
  layer1(memory, &e);
  layer2(memory, &e);
  return trigger_layer(memory, &e);
}

// The main function of the monitor.
int main(int argc, char **argv) {
    Memory memory = init();
    Event e1 = (Event) {1.0, 1.0, 1.0};
    monitor(&memory, e1, 1.0);
    Event e2 = (Event) {1.0, 1.0, 2.0};
    monitor(&memory, e2, 2.0);
    Event e3 = (Event) {1.0001, 1.0002, 0.9999};
    monitor(&memory, e3, 3.0);
}

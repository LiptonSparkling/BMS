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

typedef struct {
    float voltage_1;
    float voltage_2;
    float voltage_3;
} Event;


Memory lola_init();
int lola_monitor(Memory *memory, Event e, float time);
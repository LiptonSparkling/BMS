// The memory of stream current consists of a ring buffer of the last 2 values.
// Additionally, the index of the current (last) value in the buffer is recorder
// and whether each value in the buffer is valid.
//
// Memory for stream "current" of type Float32.
// Memory bound 2 because it is accessed by consumption with {"Offset":1}.
// All accesses to this stream:
// - consumption with {"Offset":1}, "Sync"
// - trigger_2 with "Sync"
#define CURRENT_SIZE 2
typedef struct {
  float values[CURRENT_SIZE];
  int valid[CURRENT_SIZE];
  unsigned int current;
} CURRENTBuffer;

// The memory of stream temperature_0 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "temperature_0" of type Float32.
// Memory bound 1 because it is accessed by max_temp with "Sync".
// All accesses to this stream:
// - max_temp with "Sync"
#define TEMPERATURE_0_SIZE 1
typedef struct {
  float values[TEMPERATURE_0_SIZE];
  int valid[TEMPERATURE_0_SIZE];
  unsigned int current;
} TEMPERATURE_0Buffer;

// The memory of stream temperature_1 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "temperature_1" of type Float32.
// Memory bound 1 because it is accessed by max_temp with "Sync".
// All accesses to this stream:
// - max_temp with "Sync"
#define TEMPERATURE_1_SIZE 1
typedef struct {
  float values[TEMPERATURE_1_SIZE];
  int valid[TEMPERATURE_1_SIZE];
  unsigned int current;
} TEMPERATURE_1Buffer;

// The memory of stream temperature_2 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "temperature_2" of type Float32.
// Memory bound 1 because it is accessed by max_temp with "Sync".
// All accesses to this stream:
// - max_temp with "Sync"
#define TEMPERATURE_2_SIZE 1
typedef struct {
  float values[TEMPERATURE_2_SIZE];
  int valid[TEMPERATURE_2_SIZE];
  unsigned int current;
} TEMPERATURE_2Buffer;

// The memory of stream temperature_3 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "temperature_3" of type Float32.
// Memory bound 1 because it is accessed by max_temp with "Sync".
// All accesses to this stream:
// - max_temp with "Sync"
#define TEMPERATURE_3_SIZE 1
typedef struct {
  float values[TEMPERATURE_3_SIZE];
  int valid[TEMPERATURE_3_SIZE];
  unsigned int current;
} TEMPERATURE_3Buffer;

// The memory of stream voltage_0 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "voltage_0" of type Float32.
// Memory bound 1 because it is accessed by diff_vol_0_1 with "Sync".
// All accesses to this stream:
// - diff_vol_0_1 with "Sync"
// - diff_vol_2_0 with "Sync"
// - trigger_1 with "Sync"
#define VOLTAGE_0_SIZE 1
typedef struct {
  float values[VOLTAGE_0_SIZE];
  int valid[VOLTAGE_0_SIZE];
  unsigned int current;
} VOLTAGE_0Buffer;

// The memory of stream voltage_1 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "voltage_1" of type Float32.
// Memory bound 1 because it is accessed by diff_vol_0_1 with "Sync".
// All accesses to this stream:
// - diff_vol_0_1 with "Sync"
// - diff_vol_1_2 with "Sync"
// - trigger_1 with "Sync"
#define VOLTAGE_1_SIZE 1
typedef struct {
  float values[VOLTAGE_1_SIZE];
  int valid[VOLTAGE_1_SIZE];
  unsigned int current;
} VOLTAGE_1Buffer;

// The memory of stream voltage_2 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "voltage_2" of type Float32.
// Memory bound 1 because it is accessed by diff_vol_1_2 with "Sync".
// All accesses to this stream:
// - diff_vol_1_2 with "Sync"
// - diff_vol_2_0 with "Sync"
// - trigger_1 with "Sync"
#define VOLTAGE_2_SIZE 1
typedef struct {
  float values[VOLTAGE_2_SIZE];
  int valid[VOLTAGE_2_SIZE];
  unsigned int current;
} VOLTAGE_2Buffer;

// The memory of stream current_time consists of a ring buffer of the last 2
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "current_time" of type Float32.
// Memory bound 2 because it is accessed by consumption with {"Offset":1}.
// All accesses to this stream:
// - consumption with "Sync", {"Offset":1}
#define CURRENT_TIME_SIZE 2
typedef struct {
  float values[CURRENT_TIME_SIZE];
  int valid[CURRENT_TIME_SIZE];
  unsigned int current;
} CURRENT_TIMEBuffer;

// The memory of stream diff_vol_0_1 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "diff_vol_0_1" of type Float32.
// Memory bound 1 because it is accessed by trigger_0 with "Sync".
// All accesses to this stream:
// - trigger_0 with "Sync"
#define DIFF_VOL_0_1_SIZE 1
typedef struct {
  float values[DIFF_VOL_0_1_SIZE];
  int valid[DIFF_VOL_0_1_SIZE];
  unsigned int current;
} DIFF_VOL_0_1Buffer;

// The memory of stream diff_vol_1_2 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "diff_vol_1_2" of type Float32.
// Memory bound 1 because it is accessed by trigger_0 with "Sync".
// All accesses to this stream:
// - trigger_0 with "Sync"
#define DIFF_VOL_1_2_SIZE 1
typedef struct {
  float values[DIFF_VOL_1_2_SIZE];
  int valid[DIFF_VOL_1_2_SIZE];
  unsigned int current;
} DIFF_VOL_1_2Buffer;

// The memory of stream diff_vol_2_0 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "diff_vol_2_0" of type Float32.
// Memory bound 1 because it is accessed by trigger_0 with "Sync".
// All accesses to this stream:
// - trigger_0 with "Sync"
#define DIFF_VOL_2_0_SIZE 1
typedef struct {
  float values[DIFF_VOL_2_0_SIZE];
  int valid[DIFF_VOL_2_0_SIZE];
  unsigned int current;
} DIFF_VOL_2_0Buffer;

// The memory of stream consumption consists of a ring buffer of the last 2
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "consumption" of type Float32.
// Memory bound 2 because it is accessed by consumption with {"Offset":1}.
// All accesses to this stream:
// - consumption with {"Offset":1}
// - trigger_3 with "Sync"
#define CONSUMPTION_SIZE 2
typedef struct {
  float values[CONSUMPTION_SIZE];
  int valid[CONSUMPTION_SIZE];
  unsigned int current;
} CONSUMPTIONBuffer;

// The memory of stream max_temp consists of a ring buffer of the last 1 values.
// Additionally, the index of the current (last) value in the buffer is recorder
// and whether each value in the buffer is valid.
//
// Memory for stream "max_temp" of type Float32.
// Memory bound 1 because it is accessed by trigger_4 with "Sync".
// All accesses to this stream:
// - trigger_4 with "Sync"
#define MAX_TEMP_SIZE 1
typedef struct {
  float values[MAX_TEMP_SIZE];
  int valid[MAX_TEMP_SIZE];
  unsigned int current;
} MAX_TEMPBuffer;

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
} TRIGGER_0Buffer;

// The memory of stream trigger_1 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "trigger_1" of type Bool.
// All accesses to this stream:
#define TRIGGER_1_SIZE 1
typedef struct {
  int values[TRIGGER_1_SIZE];
  int valid[TRIGGER_1_SIZE];
  unsigned int current;
} TRIGGER_1Buffer;

// The memory of stream trigger_2 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "trigger_2" of type Bool.
// All accesses to this stream:
#define TRIGGER_2_SIZE 1
typedef struct {
  int values[TRIGGER_2_SIZE];
  int valid[TRIGGER_2_SIZE];
  unsigned int current;
} TRIGGER_2Buffer;

// The memory of stream trigger_3 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "trigger_3" of type Bool.
// All accesses to this stream:
#define TRIGGER_3_SIZE 1
typedef struct {
  int values[TRIGGER_3_SIZE];
  int valid[TRIGGER_3_SIZE];
  unsigned int current;
} TRIGGER_3Buffer;

// The memory of stream trigger_4 consists of a ring buffer of the last 1
// values. Additionally, the index of the current (last) value in the buffer is
// recorder and whether each value in the buffer is valid.
//
// Memory for stream "trigger_4" of type Bool.
// All accesses to this stream:
#define TRIGGER_4_SIZE 1
typedef struct {
  int values[TRIGGER_4_SIZE];
  int valid[TRIGGER_4_SIZE];
  unsigned int current;
} TRIGGER_4Buffer;

// The memory consists of memory for each stream and each sliding window.
typedef struct {
  // current_time
  double time;
  // Streams
  CURRENTBuffer current;
  TEMPERATURE_0Buffer temperature_0;
  TEMPERATURE_1Buffer temperature_1;
  TEMPERATURE_2Buffer temperature_2;
  TEMPERATURE_3Buffer temperature_3;
  VOLTAGE_0Buffer voltage_0;
  VOLTAGE_1Buffer voltage_1;
  VOLTAGE_2Buffer voltage_2;
  CURRENT_TIMEBuffer current_time;
  DIFF_VOL_0_1Buffer diff_vol_0_1;
  DIFF_VOL_1_2Buffer diff_vol_1_2;
  DIFF_VOL_2_0Buffer diff_vol_2_0;
  CONSUMPTIONBuffer consumption;
  MAX_TEMPBuffer max_temp;
  TRIGGER_0Buffer trigger_0;
  TRIGGER_1Buffer trigger_1;
  TRIGGER_2Buffer trigger_2;
  TRIGGER_3Buffer trigger_3;
  TRIGGER_4Buffer trigger_4;
} Memory;

typedef struct {
  float current;

  float temperature_0;
  float temperature_1;
  float temperature_2;
  float temperature_3;

  float voltage_0;
  float voltage_1;
  float voltage_2;
} Event;

typedef struct {
  int trigger0;
  int trigger1;
  int trigger2;
  int trigger3;
  int trigger4;
} TriggerResults;

Memory lola_init();

TriggerResults lola_monitor(Memory *memory, Event event, float time);
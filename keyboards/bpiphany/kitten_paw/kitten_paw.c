#include "kitten_paw.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}


void keyboard_pre_init_kb(void) {
  // Call the keyboard pre init code.

  // Init LED pins
  CONFIG_LED_IO;
}


bool led_update_kb(led_t led_state) {
   
  if (led_state.num_lock) 
      USB_LED_NUM_LOCK_ON;
  else
      USB_LED_NUM_LOCK_OFF;

  if (led_state.caps_lock) 
      USB_LED_CAPS_LOCK_ON;
  else
      USB_LED_CAPS_LOCK_OFF;

  if (led_state.scroll_lock) 
      USB_LED_SCROLL_LOCK_ON;
  else
      USB_LED_SCROLL_LOCK_OFF;

  led_update_user(led_state);
  
  
  return true;
}


#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define Blue 11
#define Red 12
#define Green 13
#define Button 5

volatile bool sequence_running = false;

int64_t turn_off_green_callback(alarm_id_t id, void *user_data);
int64_t turn_off_yellow_callback(alarm_id_t id, void *user_data);
int64_t turn_off_Blue_callback(alarm_id_t id, void *user_data);

void start_led_sequence() {
    if (sequence_running) return;
    sequence_running = true;
    
    gpio_put(Blue, 1);
    gpio_put(Red, 1);
    gpio_put(Green, 1);
    add_alarm_in_ms(3000, turn_off_green_callback, NULL, false);
}
int64_t turn_off_green_callback(alarm_id_t id, void *user_data) {
    gpio_put(Green, 0);
    add_alarm_in_ms(3000, turn_off_yellow_callback, NULL, false);
    return 0;
}
int64_t turn_off_yellow_callback(alarm_id_t id, void *user_data) {
    gpio_put(Red, 0);
    add_alarm_in_ms(3000, turn_off_Blue_callback, NULL, false);
    return 0;
}
int64_t turn_off_Blue_callback(alarm_id_t id, void *user_data) {
    gpio_put(Blue, 0);
    sequence_running = false;
    return 0;
}
bool button_pressed() {
    static uint32_t last_press_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_press_time < 200) {
        return false;
    }
    last_press_time = current_time;
    return true;
}
int main() {
    stdio_init_all();
    gpio_init(Blue);
    gpio_set_dir(Blue, GPIO_OUT);
    gpio_init(Red);
    gpio_set_dir(Red, GPIO_OUT);
    gpio_init(Green);
    gpio_set_dir(Green, GPIO_OUT);
    gpio_init(Button);
    gpio_set_dir(Button, GPIO_IN);
    gpio_pull_up(Button);

    while (1) {
        if (gpio_get(Button) == 0 && button_pressed()) {
            start_led_sequence();
        }
        sleep_ms(10);
    }
}
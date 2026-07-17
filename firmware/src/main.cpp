#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "OpenDuel";

extern "C" void app_main(void)
{
	// Give the serial monitor time to attach after reset.
	vTaskDelay(pdMS_TO_TICKS(1000));

	ESP_LOGI(TAG, "OpenDuel firmware starting...");
	ESP_LOGI(TAG, "Target: ESP32-S3");
	ESP_LOGI(TAG, "Framework: ESP-IDF");
}

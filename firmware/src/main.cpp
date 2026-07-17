#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "openduel/duel/DuelState.hpp"

static const char *TAG = "OpenDuel";

extern "C" void app_main(void)
{
	// Give the serial monitor time to attach after reset.
	vTaskDelay(pdMS_TO_TICKS(1000));

	openduel::duel::DuelState duelState;

	ESP_LOGI(TAG, "OpenDuel firmware starting...");
	ESP_LOGI(TAG, "Target: ESP32-S3");
	ESP_LOGI(TAG, "Framework: ESP-IDF");

	while (true) {
		ESP_LOGI(
			TAG,
			"DuelState: P1=%d P2=%d Turn=%d Active=%d Selected=%d",
			duelState.getLifePoints(0),
			duelState.getLifePoints(1),
			duelState.getTurn(),
			duelState.getActivePlayer(),
			duelState.getSelectedPlayer()
		);

		vTaskDelay(pdMS_TO_TICKS(2000));
	}
}

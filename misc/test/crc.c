#include <inttypes.h>

uint16_t calc_crc(void *data, uint16_t len) {
	uint32_t sum = 0;
	for (;;) {
		if (len < 1)
			break;
		sum += *((uint8_t *)data);
		data += 1;
		len -= 1;
	}
	while ((len = (uint8_t)(sum >> 24)) != 0)
		sum = (uint8_t) sum + len;
	return (uint8_t) sum ^ 0xFF;
}
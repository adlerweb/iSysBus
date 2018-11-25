#pragma once

// d points to the complete frame including checksum (which is ignored) and stopbyte!
unsigned char calc_checks(const unsigned char *d, const unsigned int len);

bool check_checks(const unsigned char *d, const unsigned int len);

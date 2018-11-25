

// d points to the complete frame including checksum (which is ignored) and stopbyte
unsigned char calc_checks(const unsigned char *d, const unsigned int len) {
 unsigned int sum=0;
 for (unsigned int i=0; i<(len - 3); ++i) { // all bytes except startbyte, checksum and stopbyte
  sum += d[i+1];
 }
 return (((sum & 0xff) ^ 0xff) + 1);
};

bool check_checks(const unsigned char *d, const unsigned int len) {
  unsigned int sum=0;
  for (unsigned int i=0; i<(len - 2); ++i) {
   sum += d[i+1];
  }
     
  return 0 == (sum & 0xff);
}


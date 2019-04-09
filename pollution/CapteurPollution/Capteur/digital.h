/** Definition for the digital I/O  **/

void output_init(void);
void output_set(int pin,unsigned char value);
void input_init(void);
unsigned char input_get(int pin);

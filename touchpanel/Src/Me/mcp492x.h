#ifndef _MCP492X_H
#define _MCP492X_H
#define MCP_CS1_PORT GPIOE
#define MCP_CS1_PIN GPIO_PIN_2
#define MCP_CS2_PORT GPIOE
#define MCP_CS2_PIN GPIO_PIN_3
#define MCP_LDAC1_PORT GPIOE 
#define MCP_LDAC1_PIN GPIO_PIN_4 
#define MCP_LDAC2_PORT GPIOE 
#define MCP_LDAC2_PIN GPIO_PIN_5 
#ifdef __cplusplus
extern "C"
{
#endif
void MCP_Init();
void MCP_CS(int i);
void MCP_LDAC(int i);
void MCP_SetValue(int i, int dac);
	void MCP_RiseDac(int i);
	void MCP_FallDac(int i);
	void MCP_SetDac(int i, int val);
	int MCP_GetDac(int i);
#ifdef __cplusplus
}
#endif
#endif
(1) how to setup and run your program
1. main.cpp

I/O:
用PA_4作為AnalogOut，PB_1作為AnalogIn，PA_7作為調高頻率的button，PA_6作為調低頻率的button，PA_2作為確認調整頻率的button，USER_BUTTON作為傳送DACdata回PC端的button。
button 都使用DigitalIn的PullNone mode。利用當前的button狀態與先前儲存的button狀態比較，不同的話代表button被按過，執行功能。



# STM32F4 RTC with msec resolution and getter and setter function

Simple ZephyrOS device driver using RTC as system/sample clock. This clock can be set and read.

Setup:
The driver uses the LSE as clock source and assumes that it is connected to an 32768Hz oscilator.

With the current pre-divers setup the sub second resolutions is around 4ms. The miliseconds are calculated according to the datasheet.

note:
The time stamping function of the stm32 rtc is not used. Means that if the ZephyrOS switches the context inside "stm32_rtc_getTimestamp" function, the result in ss, t, d can have some offset.

sources:
- stm32f412 datasheet[(RM0402)](https://www.st.com/content/ccc/resource/technical/document/reference_manual/group0/4f/7b/2b/bd/04/b3/49/25/DM00180369/files/DM00180369.pdf/jcr:content/translations/en.DM00180369.pdf)
- stm32HAL LL documentation [(UM1725)](https://www.st.com/content/ccc/resource/technical/document/user_manual/2f/71/ba/b8/75/54/47/cf/DM00105879.pdf/files/DM00105879.pdf/jcr:content/translations/en.DM00105879.pdf)

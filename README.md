# PROJECT ทำ App ออมเงิน
 ### คุณสมบัติของ App
   - ช่วยในการคิดและออมเงินในการเก็บ
   - คิดคำนวณการเก็บเงินในธนาคารหรือการออมเงินแบบประจำ
   - คิดดอกเบี้ย
   
### source code
  #### Library GTK+-3.0
    - window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      - การเรียกหน้าต่าง WINDOW มา
    - val = gtk_button_new_with_label("Name");
      - การสร้างปุ่มกด
    - val = gtk_entry_new();
      - การสร้างช่อง input
### การลง GTK
  - http://www.tarnyko.net/repo/gtk3_build_system/tutorial/gtk3_tutorial.htm
 
### การใช้งาน
  - Saving
    - คือการคำนวณการออมเงินธรรมดา แต่จะมีการคิดเพิ่ม เช่น
      - Income รายรับต่อวัน
      - Expanse รายจ่าย
      - Want ของต้องการซื้อ
      - Day จำนวนวันที่จะออม
      - Need เงินที่ต้องการออม
      
 [![project_dpqewlWMus.png](https://www.img.live/images/2019/05/02/project_dpqewlWMus.png)](https://www.img.live/image/7L23Bn)
      
  - Deposit
    - การออมเงินที่มีดดอกเบี้ยแต่เป็นการออมครั้งเดียวแล้วรอดอกเบี้ย
      - Money เงินต้องการออม
      - Year จำนวนที่จะออมกี่ปี
      - Interest ดอกเบี้ย
      
[![project_UTSZFUZ5qW.png](https://www.img.live/images/2019/05/02/project_UTSZFUZ5qW.png)](https://www.img.live/image/7L2cB6)
      
  - Long term deposit
    - การออมเงินระยะยาว
      - Money เงินต้องการออมประจำในทุกๆปี
      - Year จำนวนที่จะออมกี่ปี
      - Interest ดอกเบี้ย
      
[![project_8YWYmrqLl3.png](https://www.img.live/images/2019/05/02/project_8YWYmrqLl3.png)](https://www.img.live/image/7LH3rG)

### Poster
[![Artboard1.png](https://www.img.live/images/2019/05/02/Artboard1.png)](https://www.img.live/image/7LLZqG)

### Video
   - https://youtu.be/6Kv0IlIX3f8
### ประโยชน์จากการที่ได้ใช้แอพนี้
   - ทำให้เราสามารถพอคาดคะเนในอนาคตได้ว่า ส่วนนี้ใช้เท่าไร เก็บออมเท่าไรถึงจะดี
   - สามารถวางแผนเกี่ยวเงินที่ฝากในธนาคาร ว่า อีกกี่ปี ดอกเบี้ยpercentเท่านี้ แล้วเงินที่จะได้จริงๆนั้นเท่าไร
   
### ผู้จัดทำ
  - 61070187 นายรามิล อาจหาญ
  - 61070147 นายพีรกานต์ เดชวิไลเรือง
  - 61070223 นายศุภกร รุ่งเกตุ
  - 61070265 นางสาวอัญชิษฐา บุญณะสิทธิ์

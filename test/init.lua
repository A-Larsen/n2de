local libs = require("libs.stdlib")
print("hello from lua!")
libs.init()
libs.createWindow()

while 1 do
    libs.pollEvents()
    if libs.getWindowShouldClose() == 1 then break end;
    print(libs.getKeyDown())
end
libs.quit()

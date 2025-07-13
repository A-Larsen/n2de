local libs = require("libs.stdlib")
print("hello from lua!")
libs.init()
libs.createWindow()

while libs.getWindowShouldClose() ~= 1 do
    libs.pollEvents()
    -- print(libs.getKeyDown())
    -- print(libs.getKeyUp())
    if libs.getKeyTrigger(65)  then
        print("hello")
    end
    -- if (key == 65) then print("hello") end
    -- if (key > 0) then
    --     print(key)
    -- end
end

libs.quit()

local libs = require("libs.stdlib")
print("hello from lua!")
libs.init()
libs.createWindow()

while libs.getWindowShouldClose() ~= 1 do
    libs.pollEvents()

    local key = libs.getKeyTrigger()

    if (key == 65) then print("hello") end
end

libs.quit()

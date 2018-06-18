--[[
i = 1
while i ~= #worms + 1 do
	print("\n")
	io.write(string.format("WORM : %s\n", tostring(worms[i].worm)))
	io.write(string.format("NAME : %s\n", tostring(worms[i].name)))
	io.write(string.format("POS X : %s\n", tostring(worms[i].posX)))
	io.write(string.format("POS Y : %s\n", tostring(worms[i].posY)))
	io.write(string.format("MOVE X : %s\n", tostring(worms[i].moveX)))
	io.write(string.format("MOVE Y : %s\n", tostring(worms[i].moveY)))
	io.write(string.format("LIFE : %s\n", tostring(worms[i].life)))
	io.write(string.format("FALL : %s\n", tostring(worms[i].fall)))
	io.write(string.format("TEAM : %s\n", tostring(worms[i].team)))
	print("\n");
	i = i + 1;
end

print("\n")
io.write(string.format("curr worm name : %s\n", tostring(currentWorm[1].worm)))
io.write(string.format("curr worm name : %s\n", tostring(currentWorm[1].name)))
io.write(string.format("curr worm posX : %s\n", tostring(currentWorm[1].posX)))
io.write(string.format("curr worm posY : %s\n", tostring(currentWorm[1].posY)))
io.write(string.format("curr worm moveX : %s\n", tostring(currentWorm[1].moveX)))
io.write(string.format("curr worm moveY : %s\n", tostring(currentWorm[1].moveY)))
io.write(string.format("curr worm life : %s\n", tostring(currentWorm[1].life)))
io.write(string.format("curr worm fall : %s\n", tostring(currentWorm[1].fall)))
io.write(string.format("curr worm team : %s\n", tostring(currentWorm[1].team)))
print("\n")

j = 1
while j ~= #weapons + 1 do
	print("\n")
	io.write(string.format("WEAPON ID : %s\n", tostring(weapons[j].weapon_id)))
	io.write(string.format("AMMO : %s\n", tostring(weapons[j].ammo)))
	io.write(string.format("DAMAGE : %s\n", tostring(weapons[j].damage)))
	io.write(string.format("RANGE : %s\n", tostring(weapons[j].max_range)))
	j = j +1
end
]]

--[[
	function nearest_target()
	distX = 0
	nearest = nil
	i = 1
	my_worm = currentWorm[1]

	for i, worm in ipairs(worms) do
		print(i)
		print(my_worm.posX)
		print(worm.posX)
		print(nearest)
		print("\n")
		if my_worm.team ~= worm.team then
			if distX == 0 or math.abs(my_worm.posX - worm.posX) < distX then
				distX = math.abs(my_worm.posX - worm.posX)
				nearest = my_worm.worm
			end
		end
	end
	return nearest
end
]]
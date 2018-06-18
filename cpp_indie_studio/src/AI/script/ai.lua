--[[
		1 - Do I have to move?
		2 - Which worms do I shoot?
			~ check life
			~ check pos
			~ check turn place
			~ check ennemies near target (Am I safe?)
			~ check allies near target (Friendly fire?)
		3 - Which weapon do I use?
		4 - How should I use my weapon?
	]]

my_worm = currentWorm[1]
function ShouldIMove()
	dist = 0
	should = true
	nearest = nil
	i = 1
	current_distance = 0
	
	for i, worm in ipairs(worms) do
		if my_worm.team ~= worm.team then
			current_distance = math.sqrt((math.pow(worm.posX - my_worm.posX, 2)) + (math.pow(worm.posY - my_worm.posY, 2)))
			if dist == 0 or current_distance < dist then
				dist = current_distance
				nearest = worm
			end
		end
	end

	i = 1
	for i, weapon in ipairs(weapons) do
		io.write(string.format("WEAPON : id :%s -- ammo : %s\n", tostring(weapon.weapon_id), tostring(weapon.max_range)))
		io.write(string.format("DISTANCE : %s\n", tostring(dist)))
		io.write(string.format("COORD MOI : x: %s -- y: %s\n", tostring(my_worm.posX), tostring(my_worm.posY)))
		io.write(string.format("COORD WORM : x: %s -- y: %s\n\n", tostring(nearest.posX), tostring(nearest.posY)))

		if dist <= weapon.max_range and weapon.ammo > 0 then
			should = false
		end
	end
	return should
end
	
function Move()
	dist = 0
	should = true
	nearest = nil
	i = 1
	moving = ShouldIMove()
	
	for i, worm in ipairs(worms) do
		if my_worm.team ~= worm.team then
			current_distance = math.sqrt((math.pow(worm.posX - my_worm.posX, 2)) + (math.pow(worm.posY - my_worm.posY, 2)))
			if dist == 0 or current_distance < dist then
				dist = current_distance
				nearest = worm
			end
		end
	end
	
	print(moving)
	if moving == true then
		if my_worm.posX < nearest.posX  then
			print("moving forward")
			return -1
		end
		if my_worm.posX > nearest.posX then
			print("moving backward")
			return 1
		end
	end
	return 0
end

Move()
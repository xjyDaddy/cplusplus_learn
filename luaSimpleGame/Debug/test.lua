print("script load success...\n")
function init( ... )
	print("C++ call lua: init()")
end

function updateFrame( ... )
	print("C++ call lua: updateFrame()")
	local number = GetRandomNumber(1,100)
	print("random number:" ..number)
end
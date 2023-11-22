--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type BP_MyDemoPlayerController_C
local M = UnLua.Class()

-- function M:Initialize(Initializer)
-- end

-- function M:UserConstructionScript()
-- end

local Screen = require "Blueprint.Screen"

function M:ReceiveBeginPlay()
    local msg = [[
    Hello World!
    ]]
    print(msg)
    Screen.Print(msg)
    local Widget = UE.UWidgetBlueprintLibrary.Create(self, UE.UClass.Load("/Game/ThirdPerson/UI/WBP_HUD.WBP_HUD_C"))
    Widget:AddToViewport()

end

-- function M:ReceiveEndPlay()
-- end

-- function M:ReceiveTick(DeltaSeconds)
-- end

-- function M:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
-- end

-- function M:ReceiveActorBeginOverlap(OtherActor)
-- end

-- function M:ReceiveActorEndOverlap(OtherActor)
-- end

return M

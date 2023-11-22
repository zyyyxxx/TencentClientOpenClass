--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type BP_HUD_C
local M = UnLua.Class()

--function M:Initialize(Initializer)
--end

--function M:PreConstruct(IsDesignTime)
--end

local Screen = require "Blueprint.Screen"

function M:Construct()
    self.ProgressBar_Health:SetPercent(0.1)
    self.Button_Attack.OnPressed:Add(self , M.Button_AttackCallback)
    self.Button_Jump.OnPressed:Add(self , M.Button_JumpCallback)
end

function M:Button_AttackCallback()
    local msg = [[
    Attack!
    ]]
    Screen.Print(msg)
end

function M:Button_JumpCallback()
    local msg = [[
    Jump!
    ]]
    Screen.Print(msg)
    local Pawn = self:GetOwningPlayerPawn()
    local Character = Pawn:Cast(UE.ACharacter)
    Character.Jump(Character)
end


--function M:Tick(MyGeometry, InDeltaTime)
--end

return M

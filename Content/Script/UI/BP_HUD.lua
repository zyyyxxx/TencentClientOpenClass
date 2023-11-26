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
    self.WBP_Rank:SetVisibility(1)
    self.Button_Rank.OnPressed:Add(self , M.Button_RankCallback)
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

function M:Button_RankCallback()
    local Visibility = self.WBP_Rank:GetVisibility()
    if Visibility == 0 then
        self.WBP_Rank:SetVisibility(1)
    else
        self.WBP_Rank:SetVisibility(0)
    end
end

--function M:Tick(MyGeometry, InDeltaTime)
--end

return M

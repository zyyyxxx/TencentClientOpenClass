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

function M:Construct()
    self.ProgressBar_Health:SetPercent(0.1);
end

--function M:Tick(MyGeometry, InDeltaTime)
--end

return M

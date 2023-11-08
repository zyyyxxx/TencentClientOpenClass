--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type WB_HealthBar_C
local M = UnLua.Class()

--function M:Initialize(Initializer)
--end

function M:PreConstruct(IsDesignTime)
    self.TestButton.OnClicked:Add(self , M.OnClicked_TestButton)
end

function M:OnClicked_TestButton()
    UE.UKismetSystemLibrary.PrintString(self,"Get Click Msg From UnLua ")
end

-- function M:Construct()
-- end

--function M:Tick(MyGeometry, InDeltaTime)
--end

return M

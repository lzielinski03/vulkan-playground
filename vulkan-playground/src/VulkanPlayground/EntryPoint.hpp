#pragma once

#ifdef VPL_PLATFORM_WINDOWS 
 
extern VulkanPG::Application* VulkanPG::CreateApplication();

int main(int argc, char** argv)
{
	VulkanPG::Log::Init();
	VPL_CORE_WARN("Initialized Log!");

	auto app = VulkanPG::CreateApplication();
	app->Run();
	delete app;
}

#endif
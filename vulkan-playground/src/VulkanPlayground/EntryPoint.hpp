#pragma once

#ifdef VPL_PLATFORM_WINDOWS 
 
extern VulkanPG::Application* VulkanPG::CreateApplication();

int main(int argc, char** argv) {
	auto app = VulkanPG::CreateApplication();
	app->Run();
	delete app;
}

#endif
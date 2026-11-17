#include "packagemanager.hpp"
#include <alpm.h>
#include <alpm_list.h>
#include <iostream>

PackageManager::PackageManager() {

}

int PackageManager::UpdateSyncedDatabases() {

	alpm_handle_t *handle;
	alpm_errno_t err;
	handle = alpm_initialize("/", "/var/lib/pacman/", &err);

	alpm_db_t* core_repo = alpm_register_syncdb(handle, "core", ALPM_DB_USAGE_ALL);
	alpm_db_t* extra_repo = alpm_register_syncdb(handle, "extra", ALPM_DB_USAGE_ALL);
	alpm_db_t* multilib_repo = alpm_register_syncdb(handle, "multilib", ALPM_DB_USAGE_ALL);

	alpm_db_t* localdb = alpm_get_localdb(handle);
	alpm_list_t* syncdb = alpm_get_syncdbs(handle);

	alpm_list_t* needle = nullptr;
	alpm_list_t* found = nullptr;
	if (!syncdb) {
		std::cerr << "No sync databases registered!" << std::endl;
		return 1;
	}

	return 0;
}
#pragma once

#include <memory>
#include <string>

#include "storage_EXPORTS.h"

#include "storage_credential.h"
#include "storage_url.h"

namespace azure {  namespace storage_lite {

    class storage_account final
    {
    public:
        enum class service
        {
            blob,
            table,
            queue,
            file,
            adls
        };

        static std::shared_ptr<storage_account> development_storage_account();

        AZURE_STORAGE_API storage_account(const std::string &account_name, std::shared_ptr<storage_credential> credential, bool use_https = true, const std::string &blob_endpoint = std::string());

        std::shared_ptr<storage_credential> credential() const
        {
            return m_credential;
        }

        AZURE_STORAGE_API storage_url get_url(service service) const;

    private:
        std::shared_ptr<storage_credential> m_credential;
        std::string m_blob_domain;
        std::string m_table_domain;
        std::string m_queue_domain;
        std::string m_file_domain;
        std::string m_adls_domain;

        AZURE_STORAGE_API void append_all(const std::string &part);
    };

}}  // azure::storage_lite

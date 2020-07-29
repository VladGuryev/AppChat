#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

#include <iostream>
#include <memory>
#include <string>
#include <protocol.h>

/**
 * @brief Channel Subscriber Interface 
 */
class ISubscriber
{
public:

    /**
     * @brief Entry point to handle incoming requests
     */
    virtual void start() = 0;

    /**
     * @brief Send response message to the client
     * 
     * @param response response needs to be sent
     */
    virtual void sendme(text_response_ptr response) = 0;

    /**
     * @brief Get the client id object
     * 
     * @details Returns current client id
     * 
     * @return identifier_t 
     */
    virtual identifier_t get_client_id() const = 0;

    /**
     * @brief Get the login
     * 
     * @details Return client's login
     * 
     * @return const std::string& 
     */
    virtual const std::string& get_login() const = 0;

    virtual ~ISubscriber() = default;
};

using subscriber_ptr = std::shared_ptr<ISubscriber>;

#endif // ISUBSCRIBER_H
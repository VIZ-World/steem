#pragma once

#include <graphene/api/discussion.hpp>

namespace graphene { namespace plugins { namespace tags { namespace sort {
    using graphene::api::discussion;
    using graphene::api::content_object;
    using graphene::chain::account_object;
    using protocol::asset;
    using protocol::share_type;
    using protocol::authority;
    using protocol::account_name_type;
    using protocol::public_key_type;

    struct by_trending {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<double>()(first.trending, second.trending)) {
                return true;
            } else if (std::greater<double>()(second.trending, first.trending)) {
                return false;
            }
            return std::less<content_object::id_type>()(first.id, second.id);
        }
    };

    struct by_created {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<time_point_sec>()(first.created, second.created)) {
                return true;
            } else if (std::equal_to<time_point_sec>()(first.created, second.created)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_active {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<time_point_sec>()(first.active, second.active)) {
                return true;
            } else if (std::equal_to<time_point_sec>()(first.active, second.active)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_updated {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<time_point_sec>()(first.last_update, second.last_update)) {
                return true;
            } else if (std::equal_to<time_point_sec>()(first.last_update, second.last_update)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_cashout {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::less<time_point_sec>()(first.cashout_time, second.cashout_time)) {
                return true;
            } else if (std::equal_to<time_point_sec>()(first.cashout_time, second.cashout_time)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_net_rshares {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<share_type>()(first.net_rshares, second.net_rshares)) {
                return true;
            } else if (std::equal_to<share_type>()(first.net_rshares, second.net_rshares)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_net_votes {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<int32_t>()(first.net_votes, second.net_votes)) {
                return true;
            } else if (std::equal_to<int32_t>()(first.net_votes, second.net_votes)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_children {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::less<int32_t>()(first.children, second.children)) {
                return true;
            } else if (std::equal_to<int32_t>()(first.children, second.children)) {
                return std::less<content_object::id_type>()(first.id, second.id);
            }
            return false;
        }
    };

    struct by_hot {
        bool operator()(const discussion& first, const discussion& second) const {
            if (std::greater<double>()(first.hot, second.hot)) {
                return true;
            } else if (std::greater<double>()(second.hot, first.hot)) {
                return false;
            }
            return std::less<content_object::id_type>()(first.id, second.id);
        }
    };

} } } }  // graphene::plugins::tags::sort

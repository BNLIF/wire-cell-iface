/** A field response provides access to a FieldResponse data structure.
 *
 * See also:
 *
 * Response::wire_region_average()
 *
 */

#ifndef WIRECELLIFACE_IFIELDRESPONSE
#define WIRECELLIFACE_IFIELDRESPONSE

#include "WireCellUtil/IComponent.h"
#include "WireCellUtil/Response.h"

namespace WireCell {

    class IFieldResponse : public IComponent<IFieldResponse>
    {
    public:

        virtual ~IFieldResponse() {}

        /// Return the field response data
        virtual const Response::Schema::FieldResponse& field_response() const = 0;
    };

}

#endif

/** SimpleBlob
 */  
#ifndef WIRECELL_SIMPLEBLOB
#define WIRECELL_SIMPLEBLOB


namespace WireCell
{

    class SimpleBlob : public IBlob {
    public:
        SimpleBlob(int ident, float value, float uncertainty, const RayGrid::Blob& shape)
            : m_ident(ident), m_value(value), m_uncertainty(uncertainty), m_shape(shape) { }
        virtual ~SimpleBlob();
        
        int ident() const { return m_ident; }
    
        float value() const { return m_value; }
    
        float uncertainty() const { return m_uncertainty; }
    
        const RayGrid::Blob& shape() const { return m_shape; }

    private:
        int m_ident;
        float m_value;
        float m_uncertainty;
        RayGrid::Blob m_shape;
    };



    class SimpleBlobSet : public IBlobSet {
    public:
        SimpleBlobSet(int ident, int face, const ISlice::pointer& slice)
            : m_ident(ident), m_face(face), m_slice(slice) { }
        virtual ~SimpleBlobSet();

        virtual int ident() const { return m_ident; }
        virtual int face() const { return m_face; }

        virtual ISlice::pointer slice() const { return m_slice; }

        virtual IBlob::vector blobs() const { return m_blobs; }

        int m_ident, m_face;
        ISlice::pointer m_slice;
        IBlob::vector m_blobs;
    };


}  // WireCell

#endif /* WIRECELL_SIMPLEBLOB */

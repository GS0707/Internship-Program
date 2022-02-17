import React from 'react'

function showModel({showDetails,viewList}) {
    return (
        <>
            <button className='btn btn-outline-dark position-fixed' onClick={viewList}>Back</button>
            <div className='d-flex justify-content-center m-3'>
                <div className="card  w-50">
                    <img className="card-img-top" src={showDetails.image} alt="Card image cap" />
                    <div className="card-body">
                        <h5 className="card-title">{showDetails.company} {showDetails.modelName}</h5>
                        <p className="card-text">
                            Price: {showDetails.price}<br />
                            RAM: {showDetails.ram}<br />
                            Storage: {showDetails.storage}
                        </p>
                    </div>
                </div>
            </div>
        </>
    )
}

export default showModel;
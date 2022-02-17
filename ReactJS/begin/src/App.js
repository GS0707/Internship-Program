import './App.css'
import React, { useState } from 'react'
import ShowModel from './Components/showModel';
import "../node_modules/bootstrap/dist/css/bootstrap.min.css";


function App() {

  const listMobile = [
    {
      company: "Apple",
      modelName: 'iPhone 12',
      price: 90000,
      ram: '8GB',
      storage: "128GB",
      image: require('./images/apple_12.webp'),
    },
    {
      company: "One Plus",
      modelName: 'Nord CE',
      price: 24000,
      ram: '6GB',
      storage: "128GB",
      image: require('./images/one_pluc_ce.jpg'),
    },
    {
      company: "Samsung",
      modelName: 'Galaxy A52',
      price: 55000,
      ram: '8GB',
      storage: "128GB",
      image: require('./images/samsung_a52.jpg'),
    },
    {
      company: "IQ",
      modelName: 'Z3',
      price: 17000,
      ram: '8GB',
      storage: "128GB",
      image: require('./images/iq_z3.webp'),
    },
    {
      company: "Moto",
      modelName: 'E4 Plus',
      price: 9000,
      ram: '4GB',
      storage: "32GB",
      image: require('./images/Moto-E4.jpg'),
    },
    {
      company: "Redmi",
      modelName: '7A',
      price: 8000,
      ram: '8GB',
      storage: "64GB",
      image: require('./images/redmi_7a.jpg'),
    }
  ];

  let [state, setState] = useState({
    showList: true,
    showDetails: null
  });

  const viewList = () => setState({ showList: true, showDetails: null });

  return (
    <div>

      {
        state.showList ?
          (
            <>
              <h1 className="display-6 text-center">Mobile Phones</h1>
              <div className=' d-flex justify-content-center flex-wrap gap-5 m-2'>
                {
                  listMobile.map((obj) => (
                    <div className="card border border-dark" key={obj.modelName} >
                      <img src={obj.image} className="card-img-top" alt="..." />
                      <div className="card-body">
                        <h5 className="card-title">{obj.company} {obj.modelName}</h5>
                        <button className="btn btn-outline-dark"
                          onClick={() => {
                            setState({ showList: false, showDetails: obj });
                          }}>
                          Features
                        </button>
                      </div>
                    </div>
                  ))
                }
              </div>
            </>
          ) :
          (
            <ShowModel showDetails={state.showDetails} viewList={viewList} />
          )
      }
    </div>
  );
}

export default App;

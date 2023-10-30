import "./chanList.css"
export default function ChanList({list, handleSelect}) {
        return (
            <ul className="chanList">
                {list.map((channel: any) => (
                    <li key={channel.id + "a"} onClick={() => handleSelect(channel)}>{channel.name}</li>
                ))}
            </ul>
        )
}
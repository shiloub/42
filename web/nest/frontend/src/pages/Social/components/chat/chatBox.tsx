import "./chatbox.css"
export default function Chatbox({messages}) {
    return (
        <ul className="chatbox">
            {messages.map((message: any) => (
                <li key={message.id}>{message.senderLogin}:  {message.content}</li>
            ))}
        </ul>
    )
}